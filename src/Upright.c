#include <pebble.h>

#define SENSOR_RATE ACCEL_SAMPLING_50HZ
#define CIRCLE_RADIUS 43

static Window *s_window;
static Layer *s_canvas_layer;
static GFont s_digit_font;

static int32_t s_angle = TRIG_MAX_ANGLE / 4;
static int s_numbers[4] = {0, 0, 0, 0};

static const GPoint SQUARE_CENTER = {100, 100};
static const GPoint BASE_CENTERS[4] = {
  {50, 50},
  {150, 50},
  {50, 150},
  {150, 150}
};

static void update_time_digits(const struct tm *time_now) {
  if (!time_now) {
    return;
  }

  int hour = time_now->tm_hour;

  if (!clock_is_24h_style()) {
    hour = hour > 12 ? hour - 12 : (hour == 0 ? 12 : hour);
  }

  s_numbers[0] = hour / 10;
  s_numbers[1] = hour % 10;
  s_numbers[2] = time_now->tm_min / 10;
  s_numbers[3] = time_now->tm_min % 10;
}

static void tick_handler(struct tm *time_now, TimeUnits units_changed) {
  (void)units_changed;
  update_time_digits(time_now);

  if (s_canvas_layer) {
    layer_mark_dirty(s_canvas_layer);
  }
}

static void update_smoothed_angle(int32_t measured_angle) {
  int32_t difference = measured_angle - s_angle;
  const int32_t half_turn = TRIG_MAX_ANGLE / 2;

  if (difference > half_turn) {
    difference -= TRIG_MAX_ANGLE;
  } else if (difference < -half_turn) {
    difference += TRIG_MAX_ANGLE;
  }

  /*
   * Follow half of the remaining difference each sample.
   * This feels noticeably snappier than the previous 1/3 filter.
   */
  s_angle += difference / 2;

  if (s_angle < 0) {
    s_angle += TRIG_MAX_ANGLE;
  } else if (s_angle >= TRIG_MAX_ANGLE) {
    s_angle -= TRIG_MAX_ANGLE;
  }
}

static void accel_data_handler(AccelData *data, uint32_t num_samples) {
  if (!data || num_samples == 0) {
    return;
  }

  const AccelData latest = data[num_samples - 1];

  if (latest.did_vibrate) {
    return;
  }

  update_smoothed_angle(atan2_lookup(latest.y, latest.x));

  if (s_canvas_layer) {
    layer_mark_dirty(s_canvas_layer);
  }
}

static GPoint rotate_point(GPoint point, GPoint center, int32_t angle) {
  const int32_t sin_value = sin_lookup(angle);
  const int32_t cos_value = cos_lookup(angle);

  const int32_t dx = point.x - center.x;
  const int32_t dy = point.y - center.y;

  return GPoint(
      center.x + (int16_t)((cos_value * dx - sin_value * dy) / TRIG_MAX_RATIO),
      center.y + (int16_t)((sin_value * dx + cos_value * dy) / TRIG_MAX_RATIO));
}

static void draw_digit_circle(GContext *ctx,
                              GPoint center,
                              int digit) {
  char text[2];
  snprintf(text, sizeof(text), "%d", digit);

  graphics_context_set_fill_color(ctx, GColorWhite);
  graphics_fill_circle(ctx, center, CIRCLE_RADIUS);

  graphics_context_set_text_color(ctx, GColorBlack);

  GRect text_box = GRect(
      center.x - CIRCLE_RADIUS,
      center.y - 28,
      CIRCLE_RADIUS * 2,
      56);

  graphics_draw_text(
      ctx,
      text,
      s_digit_font,
      text_box,
      GTextOverflowModeTrailingEllipsis,
      GTextAlignmentCenter,
      NULL);
}

static void canvas_update_proc(Layer *layer, GContext *ctx) {
  const GRect bounds = layer_get_bounds(layer);

  graphics_context_set_fill_color(ctx, GColorBlack);
  graphics_fill_rect(ctx, bounds, 0, GCornerNone);

  int32_t rotation = DEG_TO_TRIGANGLE(270) - s_angle;

  while (rotation < 0) {
    rotation += TRIG_MAX_ANGLE;
  }

  while (rotation >= TRIG_MAX_ANGLE) {
    rotation -= TRIG_MAX_ANGLE;
  }

  for (int i = 0; i < 4; ++i) {
    const GPoint rotated_center =
        rotate_point(BASE_CENTERS[i], SQUARE_CENTER, rotation);

    draw_digit_circle(ctx, rotated_center, s_numbers[i]);
  }
}

static void init(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);

  Layer *root_layer = window_get_root_layer(s_window);

  s_canvas_layer = layer_create(layer_get_bounds(root_layer));
  layer_set_update_proc(s_canvas_layer, canvas_update_proc);
  layer_add_child(root_layer, s_canvas_layer);

  s_digit_font = fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD);

  const time_t now = time(NULL);
  update_time_digits(localtime(&now));

  accel_service_set_sampling_rate(SENSOR_RATE);
  accel_data_service_subscribe(1, accel_data_handler);

  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);

  window_stack_push(s_window, true);
}

static void deinit(void) {
  accel_data_service_unsubscribe();
  tick_timer_service_unsubscribe();

  if (s_canvas_layer) {
    layer_destroy(s_canvas_layer);
    s_canvas_layer = NULL;
  }

  if (s_window) {
    window_destroy(s_window);
    s_window = NULL;
  }
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
