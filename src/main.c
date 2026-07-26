#include <pebble.h>
#include "vector_digits.h"

#define SENSOR_RATE ACCEL_SAMPLING_10HZ
#define SENSOR_BATCH_SIZE 1
#define FRAME_INTERVAL_MS 56

/*
 * Eine einzige gedämpfte Feder steuert die sichtbare Bewegung.
 * Dadurch entstehen Nachlauf und Übersteuern fließend aus
 * derselben Bewegung, ohne nachträglich gestarteten Bounce.
 */
#define DISPLAY_SPRING_NUMERATOR 24
#define DISPLAY_SPRING_DENOMINATOR 32

#define DISPLAY_DAMPING_NUMERATOR 15
#define DISPLAY_DAMPING_DENOMINATOR 32

#define DISPLAY_MAX_VELOCITY DEG_TO_TRIGANGLE(32)

#define DISPLAY_STOP_ERROR (TRIG_MAX_ANGLE / 1800)
#define DISPLAY_STOP_VELOCITY (TRIG_MAX_ANGLE / 2400)

#define SLOT_COUNT 4

/*
 * Festes Kegelmodell:
 *
 * Der virtuelle Neigungsvektor liegt IMMER auf einem Kreis
 * mit ungefähr 10 Grad Neigung. Es gibt keinen Zustand im
 * Inneren dieses Kreises und damit auch keinen Mittelpunkt,
 * den das Ziffernblatt überqueren könnte.
 *
 * sin(10 Grad) * 1000 mg ~= 174 mg
 */
#define CONE_RADIUS_MG 175

/*
 * Umfang der festen Kreisbahn:
 * 2 * pi * 175 mg ~= 1100 mg
 */
#define CONE_CIRCUMFERENCE_MG 1100

/*
 * Kleine reale Neigungen unter ungefähr 2 Grad erzeugen
 * überhaupt keine Bewegung. Dadurch bleibt das Ziffernblatt
 * bei waagerechter Uhr vollkommen ruhig.
 */
#define MIN_INPUT_RADIUS_MG 35
#define MIN_INPUT_RADIUS_SQUARED \
  ((int64_t)MIN_INPUT_RADIUS_MG * MIN_INPUT_RADIUS_MG)

/*
 * Echte Winkeldeadzone:
 * Sie bleibt unabhängig von der Stärke der Neigung immer gleich.
 */
#define ORBIT_ANGLE_DEADZONE DEG_TO_TRIGANGLE(4)
#define TANGENTIAL_FORCE_NOISE_FLOOR_MG 1

/*
 * Pro Sensormessung wird ungefähr ein Drittel der
 * geometrisch notwendigen Winkelkorrektur ausgeführt.
 */
#define CONE_RESPONSE_NUMERATOR 1
#define CONE_RESPONSE_DENOMINATOR 3

#define MAX_CONE_STEP (TRIG_MAX_ANGLE / 18)

static Window *s_window;
static Layer *s_canvas_layer;
static AppTimer *s_frame_timer;

static GPath *s_digit_paths[SLOT_COUNT][VECTOR_MAX_CONTOURS];
static bool s_digit_path_is_hole[SLOT_COUNT][VECTOR_MAX_CONTOURS];
static uint8_t s_digit_path_count[SLOT_COUNT];

static int s_numbers[SLOT_COUNT] = {-1, -1, -1, -1};

/*
 * Dieser Winkel ist der einzige Bewegungszustand des Kegels.
 * Er kann sich ausschließlich auf der festen Kreisbahn ändern.
 */
static int32_t s_cone_angle = TRIG_MAX_ANGLE / 4;
static int32_t s_display_angle = TRIG_MAX_ANGLE / 4;

/*
 * Geschwindigkeit der sichtbaren Federbewegung.
 * Nachlauf und Übersteuern entstehen direkt daraus.
 */
static int32_t s_display_velocity = 0;

static bool s_cone_initialized = false;

static const GPoint SLOT_CENTERS[SLOT_COUNT] = {
  {50, 50},
  {150, 50},
  {50, 150},
  {150, 150}
};

static const GPoint BOARD_CENTER = {100, 100};

static int32_t normalize_angle(int32_t angle) {
  while (angle < 0) {
    angle += TRIG_MAX_ANGLE;
  }

  while (angle >= TRIG_MAX_ANGLE) {
    angle -= TRIG_MAX_ANGLE;
  }

  return angle;
}

static int32_t shortest_angle_difference(
    int32_t from,
    int32_t to) {
  int32_t difference = to - from;
  const int32_t half_turn = TRIG_MAX_ANGLE / 2;

  if (difference > half_turn) {
    difference -= TRIG_MAX_ANGLE;
  } else if (difference < -half_turn) {
    difference += TRIG_MAX_ANGLE;
  }

  return difference;
}

static int32_t absolute_i32(int32_t value) {
  return value < 0 ? -value : value;
}

static int32_t clamp_i32(
    int32_t value,
    int32_t minimum,
    int32_t maximum) {
  if (value < minimum) {
    return minimum;
  }

  if (value > maximum) {
    return maximum;
  }

  return value;
}

static GPoint rotate_point(
    GPoint point,
    GPoint center,
    int32_t angle) {
  const int32_t sine = sin_lookup(angle);
  const int32_t cosine = cos_lookup(angle);

  const int32_t dx = point.x - center.x;
  const int32_t dy = point.y - center.y;

  return GPoint(
      center.x
          + (int16_t)(
              (cosine * dx - sine * dy)
              / TRIG_MAX_RATIO),
      center.y
          + (int16_t)(
              (sine * dx + cosine * dy)
              / TRIG_MAX_RATIO));
}

static void destroy_digit_paths_for_slot(int slot) {
  for (int i = 0; i < s_digit_path_count[slot]; ++i) {
    if (s_digit_paths[slot][i]) {
      gpath_destroy(s_digit_paths[slot][i]);
      s_digit_paths[slot][i] = NULL;
    }
  }

  s_digit_path_count[slot] = 0;
}

static bool rebuild_digit_paths_for_slot(
    int slot,
    int digit) {
  destroy_digit_paths_for_slot(slot);

  if (digit < 0 || digit >= VECTOR_GLYPH_COUNT) {
    APP_LOG(
        APP_LOG_LEVEL_ERROR,
        "Invalid vector digit %d",
        digit);
    return false;
  }

  const VectorGlyph *glyph = &VECTOR_GLYPHS[digit];

  if (glyph->contour_count > VECTOR_MAX_CONTOURS) {
    APP_LOG(
        APP_LOG_LEVEL_ERROR,
        "Digit %d has too many contours",
        digit);
    return false;
  }

  for (uint8_t i = 0; i < glyph->contour_count; ++i) {
    const VectorContour *contour = &glyph->contours[i];

    s_digit_paths[slot][i] =
        gpath_create(&contour->path_info);

    if (!s_digit_paths[slot][i]) {
      APP_LOG(
          APP_LOG_LEVEL_ERROR,
          "Could not create digit %d contour %d",
          digit,
          i);

      destroy_digit_paths_for_slot(slot);
      return false;
    }

    s_digit_path_is_hole[slot][i] = contour->is_hole;
  }

  s_digit_path_count[slot] = glyph->contour_count;
  return true;
}

static void update_time_digits(const struct tm *time_now) {
  if (!time_now) {
    return;
  }

  int hour = time_now->tm_hour;

  if (!clock_is_24h_style()) {
    hour = hour > 12
        ? hour - 12
        : (hour == 0 ? 12 : hour);
  }

  int new_numbers[SLOT_COUNT] = {
    hour / 10,
    hour % 10,
    time_now->tm_min / 10,
    time_now->tm_min % 10
  };

  if (new_numbers[0] == 1) {
    new_numbers[0] = 10;
  }

  if (new_numbers[2] == 1) {
    new_numbers[2] = 10;
  }

  for (int slot = 0; slot < SLOT_COUNT; ++slot) {
    if (new_numbers[slot] == s_numbers[slot]) {
      continue;
    }

    if (rebuild_digit_paths_for_slot(
            slot,
            new_numbers[slot])) {
      s_numbers[slot] = new_numbers[slot];
    }
  }

  if (s_canvas_layer) {
    layer_mark_dirty(s_canvas_layer);
  }
}

static void tick_handler(
    struct tm *time_now,
    TimeUnits units_changed) {
  (void)units_changed;
  update_time_digits(time_now);
}

/*
 * Tangentiale Kraft auf der festen Kegelbahn.
 *
 * Der reale Sensorvektor wird NICHT als neuer Winkel
 * übernommen. Stattdessen wird nur sein Anteil entlang
 * der Tangente an der aktuellen Kreisposition verwendet.
 *
 * Genau dadurch kann der virtuelle Kegel niemals durch
 * den Mittelpunkt springen.
 */
static int32_t calculate_tangential_force_mg(
    int32_t sensor_x,
    int32_t sensor_y) {
  const int32_t sine =
      sin_lookup(s_cone_angle);

  const int32_t cosine =
      cos_lookup(s_cone_angle);

  const int64_t tangential_force =
      -(int64_t)sine * sensor_x
      + (int64_t)cosine * sensor_y;

  return (int32_t)(
      tangential_force / TRIG_MAX_RATIO);
}

static void accel_data_handler(
    AccelData *data,
    uint32_t num_samples) {
  if (!data || num_samples == 0) {
    return;
  }

  const AccelData sample = data[num_samples - 1];

  if (sample.did_vibrate) {
    return;
  }

  const int32_t sensor_x = sample.x;
  const int32_t sensor_y = sample.y;

  const int64_t input_radius_squared =
      (int64_t)sensor_x * sensor_x
      + (int64_t)sensor_y * sensor_y;

  /*
   * Nur beim ersten Start darf eine eindeutige reale
   * Neigung die Anfangsposition des Kegels festlegen.
   * Danach wird atan2 nie wieder für die Bewegung benutzt.
   */
  if (!s_cone_initialized) {
    s_cone_initialized = true;

    if (input_radius_squared
        >= MIN_INPUT_RADIUS_SQUARED) {
      s_cone_angle =
          atan2_lookup(
              sensor_y,
              sensor_x);

      s_display_angle = s_cone_angle;
    }

    return;
  }

  /*
   * Waagerecht bedeutet: keine tangentiale Kraft.
   * Der Kegel bleibt an seiner festen Kreisposition stehen.
   */
  if (input_radius_squared
      < MIN_INPUT_RADIUS_SQUARED) {
    return;
  }

  /*
   * Die Deadzone wird als Winkel gemessen und nicht mehr
   * als feste Sensorstärke. Dadurch bleibt sie bei jeder
   * Neigung gleich groß.
   */
  const int32_t measured_angle =
      atan2_lookup(
          sensor_y,
          sensor_x);

  const int32_t angle_error =
      shortest_angle_difference(
          s_cone_angle,
          measured_angle);

  if (absolute_i32(angle_error)
      <= ORBIT_ANGLE_DEADZONE) {
    return;
  }

  const int32_t tangential_force_mg =
      calculate_tangential_force_mg(
          sensor_x,
          sensor_y);

  if (absolute_i32(tangential_force_mg)
      <= TANGENTIAL_FORCE_NOISE_FLOOR_MG) {
    return;
  }

  /*
   * Kraft entlang des Kreisumfangs in eine Winkelbewegung
   * auf genau derselben Kreisbahn umrechnen.
   */
  int32_t angle_step =
      (int32_t)(
          (int64_t)tangential_force_mg
          * TRIG_MAX_ANGLE
          * CONE_RESPONSE_NUMERATOR
          / CONE_CIRCUMFERENCE_MG
          / CONE_RESPONSE_DENOMINATOR);

  angle_step =
      clamp_i32(
          angle_step,
          -MAX_CONE_STEP,
          MAX_CONE_STEP);

  s_cone_angle =
      normalize_angle(
          s_cone_angle + angle_step);
}

static void frame_timer_handler(void *context) {
  (void)context;

  const int32_t error =
      shortest_angle_difference(
          s_display_angle,
          s_cone_angle);

  /*
   * Eine einzige Federbewegung:
   *
   * - der Fehler zum Ziel erzeugt Beschleunigung
   * - die aktuelle Geschwindigkeit erzeugt Nachlauf
   * - die Dämpfung beruhigt die Bewegung wieder
   *
   * Dadurch beginnt das Übersteuern schon aus der laufenden
   * Bewegung heraus und nicht erst nach einem sichtbaren Stopp.
   */
  const int32_t acceleration =
      (error
       * DISPLAY_SPRING_NUMERATOR)
      / DISPLAY_SPRING_DENOMINATOR;

  s_display_velocity += acceleration;

  s_display_velocity =
      (s_display_velocity
       * DISPLAY_DAMPING_NUMERATOR)
      / DISPLAY_DAMPING_DENOMINATOR;

  s_display_velocity =
      clamp_i32(
          s_display_velocity,
          -DISPLAY_MAX_VELOCITY,
          DISPLAY_MAX_VELOCITY);

  if (absolute_i32(error)
          <= DISPLAY_STOP_ERROR
      && absolute_i32(s_display_velocity)
          <= DISPLAY_STOP_VELOCITY) {
    s_display_angle = s_cone_angle;
    s_display_velocity = 0;
  } else {
    s_display_angle =
        normalize_angle(
            s_display_angle
            + s_display_velocity);
  }

  if (s_canvas_layer) {
    layer_mark_dirty(s_canvas_layer);
  }

  s_frame_timer =
      app_timer_register(
          FRAME_INTERVAL_MS,
          frame_timer_handler,
          NULL);
}

static void canvas_update_proc(
    Layer *layer,
    GContext *ctx) {
  const GRect bounds = layer_get_bounds(layer);

  graphics_context_set_fill_color(
      ctx,
      GColorBlack);

  graphics_fill_rect(
      ctx,
      bounds,
      0,
      GCornerNone);

  const int32_t rotation =
      normalize_angle(
          DEG_TO_TRIGANGLE(270)
          - s_display_angle);

  for (int slot = 0;
       slot < SLOT_COUNT;
       ++slot) {
    const GPoint rotated_center =
        rotate_point(
            SLOT_CENTERS[slot],
            BOARD_CENTER,
            rotation);

    for (int i = 0;
         i < s_digit_path_count[slot];
         ++i) {
      GPath *path = s_digit_paths[slot][i];

      if (!path) {
        continue;
      }

      graphics_context_set_fill_color(
          ctx,
          s_digit_path_is_hole[slot][i]
              ? GColorBlack
              : GColorWhite);

      gpath_move_to(path, rotated_center);
      gpath_rotate_to(path, rotation);
      gpath_draw_filled(ctx, path);
    }
  }
}

static void init(void) {
  s_window = window_create();

  window_set_background_color(
      s_window,
      GColorBlack);

  Layer *root_layer =
      window_get_root_layer(s_window);

  s_canvas_layer =
      layer_create(
          layer_get_bounds(root_layer));

  layer_set_update_proc(
      s_canvas_layer,
      canvas_update_proc);

  layer_add_child(
      root_layer,
      s_canvas_layer);

  const time_t now = time(NULL);
  update_time_digits(localtime(&now));

  accel_service_set_sampling_rate(
      SENSOR_RATE);

  accel_data_service_subscribe(
      SENSOR_BATCH_SIZE,
      accel_data_handler);

  tick_timer_service_subscribe(
      MINUTE_UNIT,
      tick_handler);

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

  for (int slot = 0;
       slot < SLOT_COUNT;
       ++slot) {
    destroy_digit_paths_for_slot(slot);
  }

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
