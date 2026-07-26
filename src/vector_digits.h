#ifndef VECTOR_DIGITS_H
#define VECTOR_DIGITS_H

#include <pebble.h>

#define VECTOR_GLYPH_COUNT 11
#define VECTOR_MAX_CONTOURS 3

typedef struct {
  GPathInfo path_info;
  bool is_hole;
} VectorContour;

typedef struct {
  const VectorContour *contours;
  uint8_t contour_count;
} VectorGlyph;

static GPoint s_glyph_0_contour_0_points[] = {
  GPoint(-42, -42),
  GPoint(-43, -40),
  GPoint(-43, -35),
  GPoint(-44, -28),
  GPoint(-44, 28),
  GPoint(-43, 35),
  GPoint(-43, 40),
  GPoint(-42, 42),
  GPoint(-40, 43),
  GPoint(-35, 43),
  GPoint(-28, 44),
  GPoint(28, 44),
  GPoint(35, 43),
  GPoint(40, 43),
  GPoint(42, 42),
  GPoint(43, 40),
  GPoint(43, 35),
  GPoint(44, 28),
  GPoint(44, -28),
  GPoint(43, -35),
  GPoint(43, -40),
  GPoint(42, -42),
  GPoint(40, -43),
  GPoint(35, -43),
  GPoint(28, -44),
  GPoint(-28, -44),
  GPoint(-35, -43),
  GPoint(-40, -43),
};

static GPoint s_glyph_0_contour_1_points[] = {
  GPoint(25, 25),
  GPoint(-25, 25),
  GPoint(-25, -25),
  GPoint(25, -25),
};

static const VectorContour s_glyph_0_contours[] = {
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_0_contour_0_points),
      .points = s_glyph_0_contour_0_points,
    },
    .is_hole = false,
  },
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_0_contour_1_points),
      .points = s_glyph_0_contour_1_points,
    },
    .is_hole = true,
  },
};

static GPoint s_glyph_1_contour_0_points[] = {
  GPoint(-17, -25),
  GPoint(-1, -25),
  GPoint(-1, 44),
  GPoint(12, 44),
  GPoint(13, 43),
  GPoint(15, 43),
  GPoint(16, 42),
  GPoint(16, 40),
  GPoint(17, 35),
  GPoint(17, -35),
  GPoint(16, -40),
  GPoint(16, -42),
  GPoint(15, -43),
  GPoint(12, -43),
  GPoint(11, -44),
  GPoint(-17, -44),
};

static const VectorContour s_glyph_1_contours[] = {
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_1_contour_0_points),
      .points = s_glyph_1_contour_0_points,
    },
    .is_hole = false,
  },
};

static GPoint s_glyph_2_contour_0_points[] = {
  GPoint(-42, -42),
  GPoint(-43, -42),
  GPoint(-43, -39),
  GPoint(-44, -38),
  GPoint(-44, -25),
  GPoint(25, -25),
  GPoint(25, -9),
  GPoint(-38, -9),
  GPoint(-40, -8),
  GPoint(-42, -8),
  GPoint(-43, -6),
  GPoint(-43, -3),
  GPoint(-44, 1),
  GPoint(-44, 34),
  GPoint(-43, 38),
  GPoint(-43, 41),
  GPoint(-42, 42),
  GPoint(-40, 43),
  GPoint(-35, 43),
  GPoint(-28, 44),
  GPoint(28, 44),
  GPoint(35, 43),
  GPoint(40, 43),
  GPoint(42, 42),
  GPoint(43, 42),
  GPoint(43, 39),
  GPoint(44, 38),
  GPoint(44, 25),
  GPoint(-25, 25),
  GPoint(-25, 9),
  GPoint(38, 9),
  GPoint(40, 8),
  GPoint(42, 8),
  GPoint(43, 6),
  GPoint(43, 3),
  GPoint(44, -1),
  GPoint(44, -34),
  GPoint(43, -38),
  GPoint(43, -41),
  GPoint(42, -42),
  GPoint(40, -43),
  GPoint(35, -43),
  GPoint(28, -44),
  GPoint(-28, -44),
  GPoint(-35, -43),
  GPoint(-40, -43),
};

static const VectorContour s_glyph_2_contours[] = {
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_2_contour_0_points),
      .points = s_glyph_2_contour_0_points,
    },
    .is_hole = false,
  },
};

static GPoint s_glyph_3_contour_0_points[] = {
  GPoint(-42, -42),
  GPoint(-43, -42),
  GPoint(-43, -40),
  GPoint(-44, -39),
  GPoint(-44, -25),
  GPoint(25, -25),
  GPoint(25, -9),
  GPoint(-25, -9),
  GPoint(-25, 9),
  GPoint(25, 9),
  GPoint(25, 25),
  GPoint(-44, 25),
  GPoint(-44, 39),
  GPoint(-43, 40),
  GPoint(-43, 42),
  GPoint(-42, 42),
  GPoint(-40, 43),
  GPoint(-35, 43),
  GPoint(-28, 44),
  GPoint(28, 44),
  GPoint(35, 43),
  GPoint(40, 43),
  GPoint(42, 42),
  GPoint(43, 40),
  GPoint(43, 35),
  GPoint(44, 28),
  GPoint(44, -28),
  GPoint(43, -35),
  GPoint(43, -40),
  GPoint(42, -42),
  GPoint(40, -43),
  GPoint(35, -43),
  GPoint(28, -44),
  GPoint(-28, -44),
  GPoint(-35, -43),
  GPoint(-40, -43),
};

static const VectorContour s_glyph_3_contours[] = {
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_3_contour_0_points),
      .points = s_glyph_3_contour_0_points,
    },
    .is_hole = false,
  },
};

static GPoint s_glyph_4_contour_0_points[] = {
  GPoint(-42, -42),
  GPoint(-43, -41),
  GPoint(-43, -38),
  GPoint(-44, -34),
  GPoint(-44, -1),
  GPoint(-43, 3),
  GPoint(-43, 6),
  GPoint(-42, 8),
  GPoint(-40, 8),
  GPoint(-38, 9),
  GPoint(25, 9),
  GPoint(25, 44),
  GPoint(38, 44),
  GPoint(39, 43),
  GPoint(42, 43),
  GPoint(42, 42),
  GPoint(43, 40),
  GPoint(43, 35),
  GPoint(44, 28),
  GPoint(44, -28),
  GPoint(43, -35),
  GPoint(43, -40),
  GPoint(42, -42),
  GPoint(42, -43),
  GPoint(39, -43),
  GPoint(38, -44),
  GPoint(25, -44),
  GPoint(25, -9),
  GPoint(-25, -9),
  GPoint(-25, -44),
  GPoint(-38, -44),
  GPoint(-39, -43),
  GPoint(-42, -43),
};

static const VectorContour s_glyph_4_contours[] = {
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_4_contour_0_points),
      .points = s_glyph_4_contour_0_points,
    },
    .is_hole = false,
  },
};

static GPoint s_glyph_5_contour_0_points[] = {
  GPoint(-42, -42),
  GPoint(-43, -41),
  GPoint(-43, -38),
  GPoint(-44, -34),
  GPoint(-44, -1),
  GPoint(-43, 3),
  GPoint(-43, 6),
  GPoint(-42, 8),
  GPoint(-40, 8),
  GPoint(-38, 9),
  GPoint(25, 9),
  GPoint(25, 25),
  GPoint(-44, 25),
  GPoint(-44, 38),
  GPoint(-43, 39),
  GPoint(-43, 42),
  GPoint(-42, 42),
  GPoint(-40, 43),
  GPoint(-35, 43),
  GPoint(-28, 44),
  GPoint(28, 44),
  GPoint(35, 43),
  GPoint(40, 43),
  GPoint(42, 42),
  GPoint(43, 41),
  GPoint(43, 38),
  GPoint(44, 34),
  GPoint(44, 1),
  GPoint(43, -3),
  GPoint(43, -6),
  GPoint(42, -8),
  GPoint(40, -8),
  GPoint(38, -9),
  GPoint(-25, -9),
  GPoint(-25, -25),
  GPoint(44, -25),
  GPoint(44, -38),
  GPoint(43, -39),
  GPoint(43, -42),
  GPoint(42, -42),
  GPoint(40, -43),
  GPoint(35, -43),
  GPoint(28, -44),
  GPoint(-28, -44),
  GPoint(-35, -43),
  GPoint(-40, -43),
};

static const VectorContour s_glyph_5_contours[] = {
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_5_contour_0_points),
      .points = s_glyph_5_contour_0_points,
    },
    .is_hole = false,
  },
};

static GPoint s_glyph_6_contour_0_points[] = {
  GPoint(-42, -42),
  GPoint(-43, -40),
  GPoint(-43, -35),
  GPoint(-44, -28),
  GPoint(-44, 28),
  GPoint(-43, 35),
  GPoint(-43, 40),
  GPoint(-42, 42),
  GPoint(-40, 43),
  GPoint(-35, 43),
  GPoint(-28, 44),
  GPoint(28, 44),
  GPoint(35, 43),
  GPoint(40, 43),
  GPoint(42, 42),
  GPoint(43, 41),
  GPoint(43, 38),
  GPoint(44, 34),
  GPoint(44, 1),
  GPoint(43, -3),
  GPoint(43, -6),
  GPoint(42, -8),
  GPoint(40, -8),
  GPoint(38, -9),
  GPoint(-25, -9),
  GPoint(-25, -25),
  GPoint(44, -25),
  GPoint(44, -38),
  GPoint(43, -39),
  GPoint(43, -42),
  GPoint(42, -42),
  GPoint(40, -43),
  GPoint(35, -43),
  GPoint(28, -44),
  GPoint(-28, -44),
  GPoint(-35, -43),
  GPoint(-40, -43),
};

static GPoint s_glyph_6_contour_1_points[] = {
  GPoint(25, 25),
  GPoint(-25, 25),
  GPoint(-25, 9),
  GPoint(25, 9),
};

static const VectorContour s_glyph_6_contours[] = {
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_6_contour_0_points),
      .points = s_glyph_6_contour_0_points,
    },
    .is_hole = false,
  },
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_6_contour_1_points),
      .points = s_glyph_6_contour_1_points,
    },
    .is_hole = true,
  },
};

static GPoint s_glyph_7_contour_0_points[] = {
  GPoint(-42, -42),
  GPoint(-43, -42),
  GPoint(-43, -40),
  GPoint(-44, -39),
  GPoint(-44, -25),
  GPoint(25, -25),
  GPoint(25, 44),
  GPoint(39, 44),
  GPoint(40, 43),
  GPoint(42, 43),
  GPoint(42, 42),
  GPoint(43, 40),
  GPoint(43, 35),
  GPoint(44, 29),
  GPoint(44, -28),
  GPoint(43, -35),
  GPoint(43, -40),
  GPoint(42, -42),
  GPoint(40, -43),
  GPoint(35, -43),
  GPoint(28, -44),
  GPoint(-29, -44),
  GPoint(-35, -43),
  GPoint(-40, -43),
};

static const VectorContour s_glyph_7_contours[] = {
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_7_contour_0_points),
      .points = s_glyph_7_contour_0_points,
    },
    .is_hole = false,
  },
};

static GPoint s_glyph_8_contour_0_points[] = {
  GPoint(-42, -42),
  GPoint(-43, -40),
  GPoint(-43, -35),
  GPoint(-44, -28),
  GPoint(-44, 28),
  GPoint(-43, 35),
  GPoint(-43, 40),
  GPoint(-42, 42),
  GPoint(-40, 43),
  GPoint(-35, 43),
  GPoint(-28, 44),
  GPoint(28, 44),
  GPoint(35, 43),
  GPoint(40, 43),
  GPoint(42, 42),
  GPoint(43, 40),
  GPoint(43, 35),
  GPoint(44, 28),
  GPoint(44, -28),
  GPoint(43, -35),
  GPoint(43, -40),
  GPoint(42, -42),
  GPoint(40, -43),
  GPoint(35, -43),
  GPoint(28, -44),
  GPoint(-28, -44),
  GPoint(-35, -43),
  GPoint(-40, -43),
};

static GPoint s_glyph_8_contour_1_points[] = {
  GPoint(25, -9),
  GPoint(-25, -9),
  GPoint(-25, -25),
  GPoint(25, -25),
};

static GPoint s_glyph_8_contour_2_points[] = {
  GPoint(25, 25),
  GPoint(-25, 25),
  GPoint(-25, 9),
  GPoint(25, 9),
};

static const VectorContour s_glyph_8_contours[] = {
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_8_contour_0_points),
      .points = s_glyph_8_contour_0_points,
    },
    .is_hole = false,
  },
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_8_contour_1_points),
      .points = s_glyph_8_contour_1_points,
    },
    .is_hole = true,
  },
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_8_contour_2_points),
      .points = s_glyph_8_contour_2_points,
    },
    .is_hole = true,
  },
};

static GPoint s_glyph_9_contour_0_points[] = {
  GPoint(-42, -42),
  GPoint(-43, -41),
  GPoint(-43, -38),
  GPoint(-44, -34),
  GPoint(-44, -1),
  GPoint(-43, 3),
  GPoint(-43, 6),
  GPoint(-42, 8),
  GPoint(-40, 8),
  GPoint(-38, 9),
  GPoint(25, 9),
  GPoint(25, 25),
  GPoint(-44, 25),
  GPoint(-44, 38),
  GPoint(-43, 39),
  GPoint(-43, 42),
  GPoint(-42, 42),
  GPoint(-40, 43),
  GPoint(-35, 43),
  GPoint(-28, 44),
  GPoint(28, 44),
  GPoint(35, 43),
  GPoint(40, 43),
  GPoint(42, 42),
  GPoint(43, 40),
  GPoint(43, 35),
  GPoint(44, 28),
  GPoint(44, -28),
  GPoint(43, -35),
  GPoint(43, -40),
  GPoint(42, -42),
  GPoint(40, -43),
  GPoint(35, -43),
  GPoint(28, -44),
  GPoint(-28, -44),
  GPoint(-35, -43),
  GPoint(-40, -43),
};

static GPoint s_glyph_9_contour_1_points[] = {
  GPoint(25, -9),
  GPoint(-25, -9),
  GPoint(-25, -25),
  GPoint(25, -25),
};

static const VectorContour s_glyph_9_contours[] = {
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_9_contour_0_points),
      .points = s_glyph_9_contour_0_points,
    },
    .is_hole = false,
  },
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_9_contour_1_points),
      .points = s_glyph_9_contour_1_points,
    },
    .is_hole = true,
  },
};

static GPoint s_glyph_10_contour_0_points[] = {
  GPoint(-17, -25),
  GPoint(-1, -25),
  GPoint(-1, 44),
  GPoint(12, 44),
  GPoint(13, 43),
  GPoint(15, 43),
  GPoint(16, 42),
  GPoint(16, 40),
  GPoint(17, 35),
  GPoint(17, -35),
  GPoint(16, -40),
  GPoint(16, -42),
  GPoint(15, -43),
  GPoint(12, -43),
  GPoint(11, -44),
  GPoint(-17, -44),
};

static const VectorContour s_glyph_10_contours[] = {
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_glyph_10_contour_0_points),
      .points = s_glyph_10_contour_0_points,
    },
    .is_hole = false,
  },
};

static const VectorGlyph VECTOR_GLYPHS[VECTOR_GLYPH_COUNT] = {
  [0] = { .contours = s_glyph_0_contours, .contour_count = 2 },
  [1] = { .contours = s_glyph_1_contours, .contour_count = 1 },
  [2] = { .contours = s_glyph_2_contours, .contour_count = 1 },
  [3] = { .contours = s_glyph_3_contours, .contour_count = 1 },
  [4] = { .contours = s_glyph_4_contours, .contour_count = 1 },
  [5] = { .contours = s_glyph_5_contours, .contour_count = 1 },
  [6] = { .contours = s_glyph_6_contours, .contour_count = 2 },
  [7] = { .contours = s_glyph_7_contours, .contour_count = 1 },
  [8] = { .contours = s_glyph_8_contours, .contour_count = 3 },
  [9] = { .contours = s_glyph_9_contours, .contour_count = 2 },
  [10] = { .contours = s_glyph_10_contours, .contour_count = 1 },
};

#endif
