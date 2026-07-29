#include <pebble.h>
#include "vector_digits.h"

#define SENSOR_RATE ACCEL_SAMPLING_10HZ

/*
 * Zwei Messwerte pro Callback:
 * 10 Hz Sensormessung bei ungefähr fünf Callbacks pro Sekunde.
 */
#define SENSOR_BATCH_SIZE 2

/*
 * Während einer Bewegung ungefähr 18 Bilder pro Sekunde.
 * Im Stillstand läuft kein Frame-Timer.
 */
#define FRAME_INTERVAL_MS 56

#define SLOT_COUNT 4

#define MIN_INPUT_RADIUS_MG 35
#define MIN_INPUT_RADIUS_SQUARED \
  ((int64_t)MIN_INPUT_RADIUS_MG * MIN_INPUT_RADIUS_MG)

/*
 * Ölbad-Modell:
 *
 * Die Scheibe wird durch das tangentiale Gewichtsdrehmoment angetrieben.
 * Das Öl erzeugt einen geschwindigkeitsabhängigen Widerstand. Trägheit
 * verlangsamt sowohl das Beschleunigen als auch das Abbremsen.
 *
 * Ein kleines Losbrechmoment verhindert Reaktionen auf winzige Bewegungen.
 */
#define DISK_ANGLE_DEADZONE DEG_TO_TRIGANGLE(4)

#define OIL_BREAKAWAY_EFFECTIVE_TORQUE 90
#define OIL_HOLD_EFFECTIVE_TORQUE 45

#define OIL_DRIVE_DIVISOR 160000
#define OIL_DRAG_NUMERATOR 3
#define OIL_DRAG_SCALE 16

#define OIL_MAX_ACCELERATION DEG_TO_TRIGANGLE(12)
#define OIL_MAX_VELOCITY DEG_TO_TRIGANGLE(32)
#define OIL_STOP_VELOCITY (TRIG_MAX_ANGLE / 3000)

static Window *s_window;
static Layer *s_canvas_layer;

#define SETTINGS_PERSIST_KEY 4243
#define LEGACY_SETTINGS_PERSIST_KEY 4242

#define SETTING_MIN 1
#define SETTING_MAX 10
#define DEFAULT_INERTIA 5
#define DEFAULT_SPEED 5
#define DEFAULT_FRICTION 5
#define DEFAULT_DEADZONE 5

typedef struct {
  uint32_t background_hex;
  uint32_t foreground_hex;
  bool show_emblem;
} LegacyWatchfaceSettings;

typedef struct {
  uint32_t background_hex;
  uint32_t foreground_hex;
  bool show_emblem;
  uint8_t inertia;
  uint8_t speed;
  uint8_t friction;
  uint8_t deadzone;
} WatchfaceSettings;

static WatchfaceSettings s_settings = {
  .background_hex = 0x000000,
  .foreground_hex = 0xFFFFFF,
  .show_emblem = true,
  .inertia = DEFAULT_INERTIA,
  .speed = DEFAULT_SPEED,
  .friction = DEFAULT_FRICTION,
  .deadzone = DEFAULT_DEADZONE
};

static uint8_t clamp_setting(int32_t value) {
  if (value < SETTING_MIN) {
    return SETTING_MIN;
  }

  if (value > SETTING_MAX) {
    return SETTING_MAX;
  }

  return (uint8_t)value;
}


static int32_t map_centered_setting(
    uint8_t setting,
    int32_t minimum,
    int32_t center,
    int32_t maximum) {
  const int32_t value = clamp_setting(setting);

  if (value <= 5) {
    return minimum
        + ((center - minimum) * (value - 1)) / 4;
  }

  return center
      + ((maximum - center) * (value - 5)) / 5;
}

static int32_t configured_inertia(void) {
  return map_centered_setting(
      s_settings.inertia,
      1,
      2,
      6);
}

static int32_t configured_speed(void) {
  return map_centered_setting(
      s_settings.speed,
      1,
      5,
      10);
}

static int32_t configured_friction(void) {
  return map_centered_setting(
      s_settings.friction,
      3,
      12,
      20);
}

static int32_t configured_deadzone_degrees(void) {
  return map_centered_setting(
      s_settings.deadzone,
      4,
      20,
      35);
}

static GColor current_background_color(void) {
  return GColorFromHEX(s_settings.background_hex);
}

static GColor current_foreground_color(void) {
  return GColorFromHEX(s_settings.foreground_hex);
}

static void save_settings(void) {
  persist_write_data(
      SETTINGS_PERSIST_KEY,
      &s_settings,
      sizeof(s_settings));
}

static void load_settings(void) {
  if (persist_exists(SETTINGS_PERSIST_KEY)) {
    persist_read_data(
        SETTINGS_PERSIST_KEY,
        &s_settings,
        sizeof(s_settings));
  } else if (persist_exists(LEGACY_SETTINGS_PERSIST_KEY)) {
    LegacyWatchfaceSettings legacy_settings = {
      .background_hex = 0x000000,
      .foreground_hex = 0xFFFFFF,
      .show_emblem = true
    };

    persist_read_data(
        LEGACY_SETTINGS_PERSIST_KEY,
        &legacy_settings,
        sizeof(legacy_settings));

    s_settings.background_hex =
        legacy_settings.background_hex;
    s_settings.foreground_hex =
        legacy_settings.foreground_hex;
    s_settings.show_emblem =
        legacy_settings.show_emblem;

    save_settings();
  }

  s_settings.inertia =
      clamp_setting(s_settings.inertia);
  s_settings.speed =
      clamp_setting(s_settings.speed);
  s_settings.friction =
      clamp_setting(s_settings.friction);
  s_settings.deadzone =
      clamp_setting(s_settings.deadzone);

  if (s_settings.inertia == 3
      && s_settings.speed == 5
      && s_settings.friction == 8
      && s_settings.deadzone == 10) {
    s_settings.inertia = 5;
    s_settings.speed = 5;
    s_settings.friction = 5;
    s_settings.deadzone = 5;
    save_settings();
  }
}

static void settings_inbox_received(
    DictionaryIterator *iterator,
    void *context) {
  (void)context;

  Tuple *background_tuple =
      dict_find(
          iterator,
          MESSAGE_KEY_BackgroundColor);

  if (background_tuple) {
    s_settings.background_hex =
        (uint32_t)background_tuple->value->int32;
  }

  Tuple *foreground_tuple =
      dict_find(
          iterator,
          MESSAGE_KEY_ForegroundColor);

  if (foreground_tuple) {
    s_settings.foreground_hex =
        (uint32_t)foreground_tuple->value->int32;
  }

  Tuple *emblem_tuple =
      dict_find(
          iterator,
          MESSAGE_KEY_ShowEmblem);

  if (emblem_tuple) {
    s_settings.show_emblem =
        emblem_tuple->value->int32 == 1;
  }

  Tuple *inertia_tuple =
      dict_find(
          iterator,
          MESSAGE_KEY_Inertia);

  if (inertia_tuple) {
    s_settings.inertia =
        clamp_setting(inertia_tuple->value->int32);
  }

  Tuple *speed_tuple =
      dict_find(
          iterator,
          MESSAGE_KEY_Speed);

  if (speed_tuple) {
    s_settings.speed =
        clamp_setting(speed_tuple->value->int32);
  }

  Tuple *friction_tuple =
      dict_find(
          iterator,
          MESSAGE_KEY_Friction);

  if (friction_tuple) {
    s_settings.friction =
        clamp_setting(friction_tuple->value->int32);
  }

  Tuple *deadzone_tuple =
      dict_find(
          iterator,
          MESSAGE_KEY_Deadzone);

  if (deadzone_tuple) {
    s_settings.deadzone =
        clamp_setting(deadzone_tuple->value->int32);
  }

  save_settings();

  if (s_window) {
    window_set_background_color(
        s_window,
        current_background_color());
  }

  if (s_canvas_layer) {
    layer_mark_dirty(s_canvas_layer);
  }
}

static AppTimer *s_frame_timer;

static GPath *s_digit_paths[SLOT_COUNT][VECTOR_MAX_CONTOURS];
static bool s_digit_path_is_hole[SLOT_COUNT][VECTOR_MAX_CONTOURS];
static uint8_t s_digit_path_count[SLOT_COUNT];

static int s_numbers[SLOT_COUNT] = {-1, -1, -1, -1};

/*
 * Frei gelagerte Scheibe mit Gewicht im Ölbad.
 */
static int32_t s_disk_angle = TRIG_MAX_ANGLE / 4;
static int32_t s_disk_target_angle = TRIG_MAX_ANGLE / 4;
static int32_t s_disk_velocity = 0;
static int32_t s_disk_torque_mg = 0;

static bool s_disk_initialized = false;
static bool s_disk_motion_active = false;

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

static void frame_timer_handler(void *context);

static void start_disk_animation(void) {
  if (s_frame_timer) {
    return;
  }

  s_frame_timer =
      app_timer_register(
          FRAME_INTERVAL_MS,
          frame_timer_handler,
          NULL);
}

/*
 * Tangentiale Schwerkraft relativ zur aktuellen Stellung
 * der Scheibe. Nur dieser Anteil erzeugt ein Drehmoment.
 */
static int32_t calculate_disk_torque_mg(
    int32_t sensor_x,
    int32_t sensor_y) {
  const int32_t sine =
      sin_lookup(s_disk_angle);

  const int32_t cosine =
      cos_lookup(s_disk_angle);

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

  const AccelData sample =
      data[num_samples - 1];

  if (sample.did_vibrate) {
    s_disk_torque_mg = 0;
    return;
  }

  const int32_t sensor_x = sample.x;
  const int32_t sensor_y = sample.y;

  const int64_t input_radius_squared =
      (int64_t)sensor_x * sensor_x
      + (int64_t)sensor_y * sensor_y;

  /*
   * Bei nahezu waagerechter Uhr gibt es keine eindeutige Richtung.
   * Eine bereits laufende Scheibe wird dann nur noch vom Öl gebremst.
   */
  if (input_radius_squared
      < MIN_INPUT_RADIUS_SQUARED) {
    s_disk_torque_mg = 0;
    return;
  }

  s_disk_target_angle =
      atan2_lookup(
          sensor_y,
          sensor_x);

  if (!s_disk_initialized) {
    s_disk_angle = s_disk_target_angle;
    s_disk_velocity = 0;
    s_disk_torque_mg = 0;
    s_disk_initialized = true;

    if (s_canvas_layer) {
      layer_mark_dirty(s_canvas_layer);
    }

    return;
  }

  const int32_t angle_error =
      shortest_angle_difference(
          s_disk_angle,
          s_disk_target_angle);

  const int32_t configured_deadzone =
      DEG_TO_TRIGANGLE(
          configured_deadzone_degrees());

  /*
   * Beim Losfahren gilt die volle einstellbare Deadzone.
   * Während der Bewegung gilt eine kleinere Halte-Deadzone,
   * damit die Scheibe im Zielbereich vom Öl ausrollen kann,
   * ohne dort künstlich festzuschnappen.
   */
  const int32_t moving_deadzone =
      configured_deadzone > DEG_TO_TRIGANGLE(1)
          ? configured_deadzone / 2
          : configured_deadzone;

  int32_t torque_mg =
      calculate_disk_torque_mg(
          sensor_x,
          sensor_y);

  if (s_disk_motion_active
      && absolute_i32(angle_error)
          <= moving_deadzone) {
    torque_mg = 0;
  }

  const int32_t effective_torque =
      torque_mg * configured_speed();

  /*
   * Haftreibung beziehungsweise Fließgrenze:
   * Im Stillstand muss sowohl die Winkeldeadzone als auch das
   * Losbrechmoment überwunden werden.
   */
  if (!s_disk_motion_active) {
    if (absolute_i32(angle_error)
            <= configured_deadzone
        || absolute_i32(effective_torque)
            < OIL_BREAKAWAY_EFFECTIVE_TORQUE) {
      s_disk_torque_mg = 0;
      return;
    }

    s_disk_motion_active = true;
  }

  s_disk_torque_mg = torque_mg;
  start_disk_animation();
}

static void frame_timer_handler(void *context) {
  (void)context;

  s_frame_timer = NULL;

  if (!s_disk_motion_active) {
    return;
  }

  const int32_t inertia =
      configured_inertia();

  const int32_t effective_torque =
      s_disk_torque_mg
      * configured_speed();

  /*
   * Einheitliches Ölbad-Modell:
   *
   *   Trägheit * Beschleunigung
   *     = Gewichtsdrehmoment - viskoser Widerstand
   */
  const int32_t drive_acceleration =
      (int32_t)(
          (int64_t)effective_torque
          * TRIG_MAX_ANGLE
          / ((int64_t)OIL_DRIVE_DIVISOR
             * inertia));

  const int32_t friction =
      configured_friction();

  /*
   * Reibung 3 entspricht ungefähr der bisherigen Abstimmung.
   * Höhere Werte erhöhen den Öl-/Lagerwiderstand deutlich und
   * reduzieren dadurch das mehrfache Nachschwingen.
   */
  const int32_t drag_acceleration =
      (int32_t)(
          (int64_t)s_disk_velocity
          * OIL_DRAG_NUMERATOR
          * friction
          / ((int64_t)OIL_DRAG_SCALE
             * inertia
             * 3));

  int32_t acceleration =
      drive_acceleration
      - drag_acceleration;

  acceleration =
      clamp_i32(
          acceleration,
          -OIL_MAX_ACCELERATION,
          OIL_MAX_ACCELERATION);

  s_disk_velocity += acceleration;

  s_disk_velocity =
      clamp_i32(
          s_disk_velocity,
          -OIL_MAX_VELOCITY,
          OIL_MAX_VELOCITY);

  if (absolute_i32(effective_torque)
          <= OIL_HOLD_EFFECTIVE_TORQUE
      && absolute_i32(s_disk_velocity)
          <= OIL_STOP_VELOCITY) {
    s_disk_velocity = 0;
    s_disk_torque_mg = 0;
    s_disk_motion_active = false;
    return;
  }

  s_disk_angle =
      normalize_angle(
          s_disk_angle
          + s_disk_velocity);

  if (s_canvas_layer) {
    layer_mark_dirty(s_canvas_layer);
  }

  start_disk_animation();
}

/*
 * Exaktes Schweizer Wappen nach dem vorgegebenen Pixelraster.
 *
 * Ursprungsraster:
 * rrrrrrrrr
 * rrrwwwrrr
 * rrrwwwrrr
 * rrrwwwrrr
 * rwwwwwwwwwr
 * rwwwwwwwwwr
 * rrrwwwrrr
 * rrrwwwrrr
 * rrrwwwrrr
 * rrrrrrrrr
 * ..rrrrr..
 * ...rrr...
 * ....r....
 *
 * Zur einheitlichen Zeichenbreite werden die 9-Pixel-Zeilen sauber
 * mittig auf 11 Pixel erweitert. Das Wappen wird auf den echten
 * Drehpunkt des Ziffernblatts zentriert: (100, 100).
 */
static void draw_center_emblem(
    Layer *layer,
    GContext *ctx) {
  (void)layer;

  static const char *EMBLEM_ROWS[14] = {
    "..RRRRRRRRR..",
    ".RRRRWWWRRRR.",
    ".RRRRWWWRRRR.",
    ".RRRRWWWRRRR.",
    ".RWWWWWWWWWR.",
    ".RWWWWWWWWWR.",
    ".RWWWWWWWWWR.",
    ".RRRRWWWRRRR.",
    ".RRRRWWWRRRR.",
    "..RRRWWWRRR..",
    "..RRRRRRRRR..",
    "....RRRRR....",
    ".....RRR.....",
    "......R......"
  };

  const int16_t emblem_width = 13;
  const int16_t emblem_height = 14;


  const GPoint pivot = BOARD_CENTER;

  const int16_t left =
      pivot.x - emblem_width / 2;

  const int16_t top =
      pivot.y - emblem_height / 2;

  for (int16_t row = 0; row < emblem_height; ++row) {
    int16_t run_start = -1;
    char current_symbol = '.';

    for (int16_t column = 0; column <= emblem_width; ++column) {
      const char symbol =
          (column < emblem_width)
              ? EMBLEM_ROWS[row][column]
              : '.';

      const bool drawable =
          symbol == 'W'
          || symbol == 'R';

      if (drawable && run_start < 0) {
        run_start = column;
        current_symbol = symbol;
        continue;
      }

      if (drawable
          && run_start >= 0
          && symbol == current_symbol) {
        continue;
      }

      if (run_start >= 0) {
        graphics_context_set_fill_color(
            ctx,
            current_symbol == 'W'
                ? GColorWhite
                : GColorRed);

        graphics_fill_rect(
            ctx,
            GRect(
                left + run_start,
                top + row,
                column - run_start,
                1),
            0,
            GCornerNone);

        run_start = -1;
        current_symbol = '.';
      }

      if (drawable) {
        run_start = column;
        current_symbol = symbol;
      }
    }
  }
}

static void canvas_update_proc(
    Layer *layer,
    GContext *ctx) {
  const GRect bounds = layer_get_bounds(layer);

  graphics_context_set_fill_color(
      ctx,
      current_background_color());

  graphics_fill_rect(
      ctx,
      bounds,
      0,
      GCornerNone);

  const int32_t rotation =
      normalize_angle(
          DEG_TO_TRIGANGLE(270)
          - s_disk_angle);

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
              ? current_background_color()
              : current_foreground_color());

      gpath_move_to(path, rotated_center);
      gpath_rotate_to(path, rotation);
      gpath_draw_filled(ctx, path);
    }
  }

  if (s_settings.show_emblem) {
    draw_center_emblem(
        layer,
        ctx);
  }

}

static void init(void) {
  load_settings();
  s_window = window_create();

  window_set_background_color(
      s_window,
      current_background_color());

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

  app_message_register_inbox_received(
      settings_inbox_received);

  app_message_open(128, 128);

  /*
   * Kein permanenter Frame-Timer:
   * Nur eine deutliche Bewegung startet die Animation.
   */
  s_frame_timer = NULL;

  window_stack_push(s_window, true);
}

static void deinit(void) {
  if (s_frame_timer) {
    app_timer_cancel(s_frame_timer);
    s_frame_timer = NULL;
  }

  app_message_deregister_callbacks();

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
