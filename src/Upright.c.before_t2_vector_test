#include <pebble.h>

#define CANVAS_SIZE 200
#define BLOCK_SIZE 97
#define DIGIT_COUNT 11
#define DIGIT_POSITION_COUNT 4

#define SENSOR_RATE ACCEL_SAMPLING_50HZ
#define FRAME_INTERVAL_MS 50
#define SUPERSAMPLE_GRID 4
#define SUPERSAMPLE_COUNT (SUPERSAMPLE_GRID * SUPERSAMPLE_GRID)

static Window *s_window;
static Layer *s_canvas_layer;
static GBitmap *s_canvas_bitmap;
static GBitmap *s_digits[DIGIT_COUNT];
static AppTimer *s_frame_timer;

static int32_t s_angle = TRIG_MAX_ANGLE / 4;

static int16_t s_sample_x[BLOCK_SIZE][SUPERSAMPLE_GRID];
static int16_t s_sample_y[BLOCK_SIZE][SUPERSAMPLE_GRID];

static const GPoint DIGIT_POSITIONS[DIGIT_POSITION_COUNT] = {
  {2, 2},
  {101, 2},
  {2, 101},
  {101, 101}
};

static const uint32_t DIGIT_RESOURCE_IDS[DIGIT_COUNT] = {
  RESOURCE_ID_IMAGE_T0,
  RESOURCE_ID_IMAGE_T1,
  RESOURCE_ID_IMAGE_T2,
  RESOURCE_ID_IMAGE_T3,
  RESOURCE_ID_IMAGE_T4,
  RESOURCE_ID_IMAGE_T5,
  RESOURCE_ID_IMAGE_T6,
  RESOURCE_ID_IMAGE_T7,
  RESOURCE_ID_IMAGE_T8,
  RESOURCE_ID_IMAGE_T9,
  RESOURCE_ID_IMAGE_T1_2
};

static bool bitmap_is_1bit(const GBitmap *bitmap) {
  return bitmap && gbitmap_get_format(bitmap) == GBitmapFormat1Bit;
}

static bool bitmap_is_8bit(const GBitmap *bitmap) {
  return bitmap && gbitmap_get_format(bitmap) == GBitmapFormat8Bit;
}

static bool get_1bit_pixel(const GBitmap *bitmap, int16_t x, int16_t y) {
  if (!bitmap_is_1bit(bitmap)) {
    return false;
  }

  const GRect bounds = gbitmap_get_bounds(bitmap);

  if (x < bounds.origin.x ||
      y < bounds.origin.y ||
      x >= bounds.origin.x + bounds.size.w ||
      y >= bounds.origin.y + bounds.size.h) {
    return false;
  }

  const GBitmapDataRowInfo row =
      gbitmap_get_data_row_info(bitmap, (uint16_t)y);

  if (x < row.min_x || x > row.max_x) {
    return false;
  }

  const uint8_t mask = (uint8_t)(1U << (x & 7));
  return (row.data[x >> 3] & mask) != 0;
}

static void set_8bit_pixel(GBitmap *bitmap,
                           int16_t x,
                           int16_t y,
                           GColor color) {
  if (!bitmap_is_8bit(bitmap)) {
    return;
  }

  const GRect bounds = gbitmap_get_bounds(bitmap);

  if (x < bounds.origin.x ||
      y < bounds.origin.y ||
      x >= bounds.origin.x + bounds.size.w ||
      y >= bounds.origin.y + bounds.size.h) {
    return;
  }

  const GBitmapDataRowInfo row =
      gbitmap_get_data_row_info(bitmap, (uint16_t)y);

  if (x < row.min_x || x > row.max_x) {
    return;
  }

  row.data[x] = color.argb;
}

static GColor coverage_to_grayscale(uint8_t coverage) {
  /*
   * Emery stores two bits per color channel. Convert the measured
   * 0..16 pixel coverage into the four available gray levels:
   * black, dark gray, light gray and white.
   */
  const uint8_t level =
      (uint8_t)((coverage * 3U + (SUPERSAMPLE_COUNT / 2U)) /
                SUPERSAMPLE_COUNT);

  const uint8_t component = (uint8_t)(level * 85U);
  return GColorFromRGB(component, component, component);
}

static void clear_canvas(void) {
  if (!bitmap_is_8bit(s_canvas_bitmap)) {
    return;
  }

  const GRect bounds = gbitmap_get_bounds(s_canvas_bitmap);

  for (int16_t y = 0; y < bounds.size.h; ++y) {
    const GBitmapDataRowInfo row =
        gbitmap_get_data_row_info(s_canvas_bitmap, (uint16_t)y);

    for (int16_t x = row.min_x; x <= row.max_x; ++x) {
      row.data[x] = GColorBlack.argb;
    }
  }
}

static void prepare_sampling_grid(const GBitmap *source) {
  const GRect source_bounds = gbitmap_get_bounds(source);
  const int32_t denominator = BLOCK_SIZE * SUPERSAMPLE_GRID;

  for (int16_t destination = 0;
       destination < BLOCK_SIZE;
       ++destination) {
    for (int16_t sample = 0;
         sample < SUPERSAMPLE_GRID;
         ++sample) {
      const int32_t sample_position =
          destination * SUPERSAMPLE_GRID + sample;

      s_sample_x[destination][sample] =
          source_bounds.origin.x +
          (int16_t)((sample_position * source_bounds.size.w) /
                    denominator);

      s_sample_y[destination][sample] =
          source_bounds.origin.y +
          (int16_t)((sample_position * source_bounds.size.h) /
                    denominator);
    }
  }
}

static uint8_t get_scaled_pixel_coverage(const GBitmap *source,
                                         int16_t destination_x,
                                         int16_t destination_y) {
  uint8_t coverage = 0;

  for (int16_t sample_y = 0;
       sample_y < SUPERSAMPLE_GRID;
       ++sample_y) {
    const int16_t source_y =
        s_sample_y[destination_y][sample_y];

    for (int16_t sample_x = 0;
         sample_x < SUPERSAMPLE_GRID;
         ++sample_x) {
      const int16_t source_x =
          s_sample_x[destination_x][sample_x];

      if (get_1bit_pixel(source, source_x, source_y)) {
        ++coverage;
      }
    }
  }

  return coverage;
}

static void copy_scaled_digit(const GBitmap *source,
                              GBitmap *destination,
                              GPoint destination_origin) {
  if (!bitmap_is_1bit(source) || !bitmap_is_8bit(destination)) {
    return;
  }

  for (int16_t destination_y = 0;
       destination_y < BLOCK_SIZE;
       ++destination_y) {
    for (int16_t destination_x = 0;
         destination_x < BLOCK_SIZE;
         ++destination_x) {
      const uint8_t coverage =
          get_scaled_pixel_coverage(
              source,
              destination_x,
              destination_y);

      set_8bit_pixel(
          destination,
          destination_origin.x + destination_x,
          destination_origin.y + destination_y,
          coverage_to_grayscale(coverage));
    }
  }
}

static void rebuild_time_bitmap(const struct tm *time_now) {
  if (!time_now || !s_canvas_bitmap) {
    return;
  }

  int hour = time_now->tm_hour;

  if (!clock_is_24h_style()) {
    hour = hour > 12 ? hour - 12 : (hour == 0 ? 12 : hour);
  }

  int numbers[DIGIT_POSITION_COUNT] = {
    hour / 10,
    hour % 10,
    time_now->tm_min / 10,
    time_now->tm_min % 10
  };

  if (numbers[0] == 1) {
    numbers[0] = 10;
  }

  if (numbers[2] == 1) {
    numbers[2] = 10;
  }

  clear_canvas();

  for (int i = 0; i < DIGIT_POSITION_COUNT; ++i) {
    copy_scaled_digit(
        s_digits[numbers[i]],
        s_canvas_bitmap,
        DIGIT_POSITIONS[i]);
  }

  if (s_canvas_layer) {
    layer_mark_dirty(s_canvas_layer);
  }
}

static void tick_handler(struct tm *time_now, TimeUnits units_changed) {
  (void)units_changed;
  rebuild_time_bitmap(time_now);
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
   * The sensor runs at 50 Hz. Following one third of the remaining
   * angular distance per sample keeps the motion smooth but responsive.
   */
  s_angle += difference / 3;

  if (s_angle < 0) {
    s_angle += TRIG_MAX_ANGLE;
  } else if (s_angle >= TRIG_MAX_ANGLE) {
    s_angle -= TRIG_MAX_ANGLE;
  }
}

static void accel_data_handler(AccelData *data,
                               uint32_t num_samples) {
  if (!data || num_samples == 0) {
    return;
  }

  const AccelData latest = data[num_samples - 1];

  if (latest.did_vibrate) {
    return;
  }

  update_smoothed_angle(atan2_lookup(latest.y, latest.x));
}

static void frame_timer_handler(void *context) {
  (void)context;

  if (s_canvas_layer) {
    layer_mark_dirty(s_canvas_layer);
  }

  s_frame_timer =
      app_timer_register(
          FRAME_INTERVAL_MS,
          frame_timer_handler,
          NULL);
}

static void canvas_update_proc(Layer *layer, GContext *ctx) {
  const GRect bounds = layer_get_bounds(layer);

  graphics_context_set_fill_color(ctx, GColorBlack);
  graphics_fill_rect(ctx, bounds, 0, GCornerNone);

  if (!s_canvas_bitmap) {
    return;
  }

  int32_t rotation = DEG_TO_TRIGANGLE(270) - s_angle;

  while (rotation < 0) {
    rotation += TRIG_MAX_ANGLE;
  }

  while (rotation >= TRIG_MAX_ANGLE) {
    rotation -= TRIG_MAX_ANGLE;
  }

  graphics_context_set_compositing_mode(ctx, GCompOpAssign);

  graphics_draw_rotated_bitmap(
      ctx,
      s_canvas_bitmap,
      GPoint(CANVAS_SIZE / 2, CANVAS_SIZE / 2),
      rotation,
      GPoint(CANVAS_SIZE / 2, CANVAS_SIZE / 2));
}

static bool load_resources(void) {
  s_canvas_bitmap =
      gbitmap_create_blank(
          GSize(CANVAS_SIZE, CANVAS_SIZE),
          GBitmapFormat8Bit);

  if (!s_canvas_bitmap) {
    APP_LOG(
        APP_LOG_LEVEL_ERROR,
        "Could not create 8-bit canvas bitmap");
    return false;
  }

  for (int i = 0; i < DIGIT_COUNT; ++i) {
    s_digits[i] =
        gbitmap_create_with_resource(DIGIT_RESOURCE_IDS[i]);

    if (!s_digits[i]) {
      APP_LOG(
          APP_LOG_LEVEL_ERROR,
          "Could not load digit resource %d",
          i);
      return false;
    }

    if (!bitmap_is_1bit(s_digits[i])) {
      APP_LOG(
          APP_LOG_LEVEL_ERROR,
          "Digit resource %d is not 1-bit",
          i);
      return false;
    }
  }

  prepare_sampling_grid(s_digits[0]);
  return true;
}

static void unload_resources(void) {
  for (int i = 0; i < DIGIT_COUNT; ++i) {
    if (s_digits[i]) {
      gbitmap_destroy(s_digits[i]);
      s_digits[i] = NULL;
    }
  }

  if (s_canvas_bitmap) {
    gbitmap_destroy(s_canvas_bitmap);
    s_canvas_bitmap = NULL;
  }
}

static void init(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);

  Layer *root_layer = window_get_root_layer(s_window);

  s_canvas_layer =
      layer_create(layer_get_bounds(root_layer));

  layer_set_update_proc(
      s_canvas_layer,
      canvas_update_proc);

  layer_add_child(root_layer, s_canvas_layer);

  if (!load_resources()) {
    APP_LOG(
        APP_LOG_LEVEL_ERROR,
        "Resource initialization failed");
  }

  const time_t now = time(NULL);
  rebuild_time_bitmap(localtime(&now));

  accel_service_set_sampling_rate(SENSOR_RATE);
  accel_data_service_subscribe(1, accel_data_handler);

  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);

  s_frame_timer =
      app_timer_register(
          FRAME_INTERVAL_MS,
          frame_timer_handler,
          NULL);

  window_stack_push(s_window, true);
}

static void deinit(void) {
  if (s_frame_timer) {
    app_timer_cancel(s_frame_timer);
    s_frame_timer = NULL;
  }

  accel_data_service_unsubscribe();
  tick_timer_service_unsubscribe();

  if (s_canvas_layer) {
    layer_destroy(s_canvas_layer);
    s_canvas_layer = NULL;
  }

  unload_resources();

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
