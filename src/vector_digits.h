#ifndef VECTOR_DIGITS_H
#define VECTOR_DIGITS_H

#include <pebble.h>

#define CANVAS_CENTER_X 100
#define CANVAS_CENTER_Y 100

typedef struct {
  GPathInfo path_info;
  bool is_hole;
} VectorContour;

typedef struct {
  const VectorContour *contours;
  uint8_t contour_count;
} VectorGlyph;

static const GPoint s_slot_0_digit_0_contour_0_points[] = {
  GPoint(-7, -95),
  GPoint(-7, -94),
  GPoint(-5, -94),
  GPoint(-5, -92),
  GPoint(-4, -92),
  GPoint(-4, -7),
  GPoint(-5, -7),
  GPoint(-5, -5),
  GPoint(-7, -5),
  GPoint(-7, -4),
  GPoint(-92, -4),
  GPoint(-92, -5),
  GPoint(-94, -5),
  GPoint(-94, -7),
  GPoint(-95, -7),
  GPoint(-95, -92),
  GPoint(-94, -92),
  GPoint(-94, -94),
  GPoint(-92, -94),
  GPoint(-92, -95),
};

static const GPoint s_slot_0_digit_0_contour_1_points[] = {
  GPoint(-76, -76),
  GPoint(-76, -23),
  GPoint(-23, -23),
  GPoint(-23, -76),
};

static const VectorContour s_slot_0_digit_0_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_0_contour_0_points), .points = (GPoint *)s_slot_0_digit_0_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_0_contour_1_points), .points = (GPoint *)s_slot_0_digit_0_contour_1_points }, .is_hole = true },
};

static const GPoint s_slot_0_digit_1_contour_0_points[] = {
  GPoint(-4, -7),
  GPoint(-5, -7),
  GPoint(-5, -5),
  GPoint(-7, -5),
  GPoint(-7, -4),
  GPoint(-23, -4),
  GPoint(-23, -76),
  GPoint(-40, -76),
  GPoint(-40, -95),
  GPoint(-7, -95),
  GPoint(-7, -94),
  GPoint(-5, -94),
  GPoint(-5, -92),
  GPoint(-4, -92),
};

static const VectorContour s_slot_0_digit_1_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_1_contour_0_points), .points = (GPoint *)s_slot_0_digit_1_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_0_digit_2_contour_0_points[] = {
  GPoint(-7, -95),
  GPoint(-7, -94),
  GPoint(-5, -94),
  GPoint(-5, -92),
  GPoint(-4, -92),
  GPoint(-4, -43),
  GPoint(-5, -43),
  GPoint(-5, -41),
  GPoint(-7, -41),
  GPoint(-7, -40),
  GPoint(-76, -40),
  GPoint(-76, -23),
  GPoint(-4, -23),
  GPoint(-4, -7),
  GPoint(-5, -7),
  GPoint(-5, -5),
  GPoint(-7, -5),
  GPoint(-7, -4),
  GPoint(-92, -4),
  GPoint(-92, -5),
  GPoint(-94, -5),
  GPoint(-94, -7),
  GPoint(-95, -7),
  GPoint(-95, -56),
  GPoint(-94, -56),
  GPoint(-94, -58),
  GPoint(-92, -58),
  GPoint(-92, -59),
  GPoint(-23, -59),
  GPoint(-23, -76),
  GPoint(-95, -76),
  GPoint(-95, -92),
  GPoint(-94, -92),
  GPoint(-94, -94),
  GPoint(-92, -94),
  GPoint(-92, -95),
};

static const VectorContour s_slot_0_digit_2_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_2_contour_0_points), .points = (GPoint *)s_slot_0_digit_2_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_0_digit_3_contour_0_points[] = {
  GPoint(-7, -95),
  GPoint(-7, -94),
  GPoint(-5, -94),
  GPoint(-5, -92),
  GPoint(-4, -92),
  GPoint(-4, -7),
  GPoint(-5, -7),
  GPoint(-5, -5),
  GPoint(-7, -5),
  GPoint(-7, -4),
  GPoint(-92, -4),
  GPoint(-92, -5),
  GPoint(-94, -5),
  GPoint(-94, -7),
  GPoint(-95, -7),
  GPoint(-95, -23),
  GPoint(-23, -23),
  GPoint(-23, -40),
  GPoint(-76, -40),
  GPoint(-76, -59),
  GPoint(-23, -59),
  GPoint(-23, -76),
  GPoint(-95, -76),
  GPoint(-95, -92),
  GPoint(-94, -92),
  GPoint(-94, -94),
  GPoint(-92, -94),
  GPoint(-92, -95),
};

static const VectorContour s_slot_0_digit_3_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_3_contour_0_points), .points = (GPoint *)s_slot_0_digit_3_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_0_digit_4_contour_0_points[] = {
  GPoint(-23, -40),
  GPoint(-92, -40),
  GPoint(-92, -41),
  GPoint(-94, -41),
  GPoint(-94, -43),
  GPoint(-95, -43),
  GPoint(-95, -92),
  GPoint(-94, -92),
  GPoint(-94, -94),
  GPoint(-92, -94),
  GPoint(-92, -95),
  GPoint(-76, -95),
  GPoint(-76, -59),
  GPoint(-23, -59),
  GPoint(-23, -95),
  GPoint(-7, -95),
  GPoint(-7, -94),
  GPoint(-5, -94),
  GPoint(-5, -92),
  GPoint(-4, -92),
  GPoint(-4, -7),
  GPoint(-5, -7),
  GPoint(-5, -5),
  GPoint(-7, -5),
  GPoint(-7, -4),
  GPoint(-23, -4),
};

static const VectorContour s_slot_0_digit_4_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_4_contour_0_points), .points = (GPoint *)s_slot_0_digit_4_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_0_digit_5_contour_0_points[] = {
  GPoint(-7, -95),
  GPoint(-7, -94),
  GPoint(-5, -94),
  GPoint(-5, -92),
  GPoint(-4, -92),
  GPoint(-4, -76),
  GPoint(-76, -76),
  GPoint(-76, -59),
  GPoint(-7, -59),
  GPoint(-7, -58),
  GPoint(-5, -58),
  GPoint(-5, -56),
  GPoint(-4, -56),
  GPoint(-4, -7),
  GPoint(-5, -7),
  GPoint(-5, -5),
  GPoint(-7, -5),
  GPoint(-7, -4),
  GPoint(-92, -4),
  GPoint(-92, -5),
  GPoint(-94, -5),
  GPoint(-94, -7),
  GPoint(-95, -7),
  GPoint(-95, -23),
  GPoint(-23, -23),
  GPoint(-23, -40),
  GPoint(-92, -40),
  GPoint(-92, -41),
  GPoint(-94, -41),
  GPoint(-94, -43),
  GPoint(-95, -43),
  GPoint(-95, -92),
  GPoint(-94, -92),
  GPoint(-94, -94),
  GPoint(-92, -94),
  GPoint(-92, -95),
};

static const VectorContour s_slot_0_digit_5_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_5_contour_0_points), .points = (GPoint *)s_slot_0_digit_5_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_0_digit_6_contour_0_points[] = {
  GPoint(-7, -95),
  GPoint(-7, -94),
  GPoint(-5, -94),
  GPoint(-5, -92),
  GPoint(-4, -92),
  GPoint(-4, -76),
  GPoint(-76, -76),
  GPoint(-76, -59),
  GPoint(-7, -59),
  GPoint(-7, -58),
  GPoint(-5, -58),
  GPoint(-5, -56),
  GPoint(-4, -56),
  GPoint(-4, -7),
  GPoint(-5, -7),
  GPoint(-5, -5),
  GPoint(-7, -5),
  GPoint(-7, -4),
  GPoint(-92, -4),
  GPoint(-92, -5),
  GPoint(-94, -5),
  GPoint(-94, -7),
  GPoint(-95, -7),
  GPoint(-95, -92),
  GPoint(-94, -92),
  GPoint(-94, -94),
  GPoint(-92, -94),
  GPoint(-92, -95),
};

static const GPoint s_slot_0_digit_6_contour_1_points[] = {
  GPoint(-76, -40),
  GPoint(-76, -23),
  GPoint(-23, -23),
  GPoint(-23, -40),
};

static const VectorContour s_slot_0_digit_6_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_6_contour_0_points), .points = (GPoint *)s_slot_0_digit_6_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_6_contour_1_points), .points = (GPoint *)s_slot_0_digit_6_contour_1_points }, .is_hole = true },
};

static const GPoint s_slot_0_digit_7_contour_0_points[] = {
  GPoint(-7, -95),
  GPoint(-7, -94),
  GPoint(-5, -94),
  GPoint(-5, -92),
  GPoint(-4, -92),
  GPoint(-4, -7),
  GPoint(-5, -7),
  GPoint(-5, -5),
  GPoint(-7, -5),
  GPoint(-7, -4),
  GPoint(-23, -4),
  GPoint(-23, -76),
  GPoint(-95, -76),
  GPoint(-95, -92),
  GPoint(-94, -92),
  GPoint(-94, -94),
  GPoint(-92, -94),
  GPoint(-92, -95),
};

static const VectorContour s_slot_0_digit_7_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_7_contour_0_points), .points = (GPoint *)s_slot_0_digit_7_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_0_digit_8_contour_0_points[] = {
  GPoint(-7, -95),
  GPoint(-7, -94),
  GPoint(-5, -94),
  GPoint(-5, -92),
  GPoint(-4, -92),
  GPoint(-4, -7),
  GPoint(-5, -7),
  GPoint(-5, -5),
  GPoint(-7, -5),
  GPoint(-7, -4),
  GPoint(-92, -4),
  GPoint(-92, -5),
  GPoint(-94, -5),
  GPoint(-94, -7),
  GPoint(-95, -7),
  GPoint(-95, -92),
  GPoint(-94, -92),
  GPoint(-94, -94),
  GPoint(-92, -94),
  GPoint(-92, -95),
};

static const GPoint s_slot_0_digit_8_contour_1_points[] = {
  GPoint(-76, -40),
  GPoint(-76, -23),
  GPoint(-23, -23),
  GPoint(-23, -40),
};

static const GPoint s_slot_0_digit_8_contour_2_points[] = {
  GPoint(-23, -59),
  GPoint(-23, -76),
  GPoint(-76, -76),
  GPoint(-76, -59),
};

static const VectorContour s_slot_0_digit_8_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_8_contour_0_points), .points = (GPoint *)s_slot_0_digit_8_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_8_contour_1_points), .points = (GPoint *)s_slot_0_digit_8_contour_1_points }, .is_hole = true },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_8_contour_2_points), .points = (GPoint *)s_slot_0_digit_8_contour_2_points }, .is_hole = true },
};

static const GPoint s_slot_0_digit_9_contour_0_points[] = {
  GPoint(-7, -95),
  GPoint(-7, -94),
  GPoint(-5, -94),
  GPoint(-5, -92),
  GPoint(-4, -92),
  GPoint(-4, -7),
  GPoint(-5, -7),
  GPoint(-5, -5),
  GPoint(-7, -5),
  GPoint(-7, -4),
  GPoint(-92, -4),
  GPoint(-92, -5),
  GPoint(-94, -5),
  GPoint(-94, -7),
  GPoint(-95, -7),
  GPoint(-95, -23),
  GPoint(-23, -23),
  GPoint(-23, -40),
  GPoint(-92, -40),
  GPoint(-92, -41),
  GPoint(-94, -41),
  GPoint(-94, -43),
  GPoint(-95, -43),
  GPoint(-95, -92),
  GPoint(-94, -92),
  GPoint(-94, -94),
  GPoint(-92, -94),
  GPoint(-92, -95),
};

static const GPoint s_slot_0_digit_9_contour_1_points[] = {
  GPoint(-23, -59),
  GPoint(-23, -76),
  GPoint(-76, -76),
  GPoint(-76, -59),
};

static const VectorContour s_slot_0_digit_9_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_9_contour_0_points), .points = (GPoint *)s_slot_0_digit_9_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_9_contour_1_points), .points = (GPoint *)s_slot_0_digit_9_contour_1_points }, .is_hole = true },
};

static const GPoint s_slot_0_digit_10_contour_0_points[] = {
  GPoint(-59, -76),
  GPoint(-59, -95),
  GPoint(-26, -95),
  GPoint(-26, -94),
  GPoint(-25, -94),
  GPoint(-25, -92),
  GPoint(-23, -92),
  GPoint(-23, -7),
  GPoint(-25, -7),
  GPoint(-25, -5),
  GPoint(-26, -5),
  GPoint(-26, -4),
  GPoint(-43, -4),
  GPoint(-43, -76),
};

static const VectorContour s_slot_0_digit_10_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_0_digit_10_contour_0_points), .points = (GPoint *)s_slot_0_digit_10_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_1_digit_0_contour_0_points[] = {
  GPoint(92, -95),
  GPoint(92, -94),
  GPoint(94, -94),
  GPoint(94, -92),
  GPoint(95, -92),
  GPoint(95, -7),
  GPoint(94, -7),
  GPoint(94, -5),
  GPoint(92, -5),
  GPoint(92, -4),
  GPoint(7, -4),
  GPoint(7, -5),
  GPoint(5, -5),
  GPoint(5, -7),
  GPoint(4, -7),
  GPoint(4, -92),
  GPoint(5, -92),
  GPoint(5, -94),
  GPoint(7, -94),
  GPoint(7, -95),
};

static const GPoint s_slot_1_digit_0_contour_1_points[] = {
  GPoint(23, -76),
  GPoint(23, -23),
  GPoint(76, -23),
  GPoint(76, -76),
};

static const VectorContour s_slot_1_digit_0_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_0_contour_0_points), .points = (GPoint *)s_slot_1_digit_0_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_0_contour_1_points), .points = (GPoint *)s_slot_1_digit_0_contour_1_points }, .is_hole = true },
};

static const GPoint s_slot_1_digit_1_contour_0_points[] = {
  GPoint(95, -7),
  GPoint(94, -7),
  GPoint(94, -5),
  GPoint(92, -5),
  GPoint(92, -4),
  GPoint(76, -4),
  GPoint(76, -76),
  GPoint(59, -76),
  GPoint(59, -95),
  GPoint(92, -95),
  GPoint(92, -94),
  GPoint(94, -94),
  GPoint(94, -92),
  GPoint(95, -92),
};

static const VectorContour s_slot_1_digit_1_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_1_contour_0_points), .points = (GPoint *)s_slot_1_digit_1_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_1_digit_2_contour_0_points[] = {
  GPoint(92, -95),
  GPoint(92, -94),
  GPoint(94, -94),
  GPoint(94, -92),
  GPoint(95, -92),
  GPoint(95, -43),
  GPoint(94, -43),
  GPoint(94, -41),
  GPoint(92, -41),
  GPoint(92, -40),
  GPoint(23, -40),
  GPoint(23, -23),
  GPoint(95, -23),
  GPoint(95, -7),
  GPoint(94, -7),
  GPoint(94, -5),
  GPoint(92, -5),
  GPoint(92, -4),
  GPoint(7, -4),
  GPoint(7, -5),
  GPoint(5, -5),
  GPoint(5, -7),
  GPoint(4, -7),
  GPoint(4, -56),
  GPoint(5, -56),
  GPoint(5, -58),
  GPoint(7, -58),
  GPoint(7, -59),
  GPoint(76, -59),
  GPoint(76, -76),
  GPoint(4, -76),
  GPoint(4, -92),
  GPoint(5, -92),
  GPoint(5, -94),
  GPoint(7, -94),
  GPoint(7, -95),
};

static const VectorContour s_slot_1_digit_2_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_2_contour_0_points), .points = (GPoint *)s_slot_1_digit_2_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_1_digit_3_contour_0_points[] = {
  GPoint(92, -95),
  GPoint(92, -94),
  GPoint(94, -94),
  GPoint(94, -92),
  GPoint(95, -92),
  GPoint(95, -7),
  GPoint(94, -7),
  GPoint(94, -5),
  GPoint(92, -5),
  GPoint(92, -4),
  GPoint(7, -4),
  GPoint(7, -5),
  GPoint(5, -5),
  GPoint(5, -7),
  GPoint(4, -7),
  GPoint(4, -23),
  GPoint(76, -23),
  GPoint(76, -40),
  GPoint(23, -40),
  GPoint(23, -59),
  GPoint(76, -59),
  GPoint(76, -76),
  GPoint(4, -76),
  GPoint(4, -92),
  GPoint(5, -92),
  GPoint(5, -94),
  GPoint(7, -94),
  GPoint(7, -95),
};

static const VectorContour s_slot_1_digit_3_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_3_contour_0_points), .points = (GPoint *)s_slot_1_digit_3_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_1_digit_4_contour_0_points[] = {
  GPoint(76, -40),
  GPoint(7, -40),
  GPoint(7, -41),
  GPoint(5, -41),
  GPoint(5, -43),
  GPoint(4, -43),
  GPoint(4, -92),
  GPoint(5, -92),
  GPoint(5, -94),
  GPoint(7, -94),
  GPoint(7, -95),
  GPoint(23, -95),
  GPoint(23, -59),
  GPoint(76, -59),
  GPoint(76, -95),
  GPoint(92, -95),
  GPoint(92, -94),
  GPoint(94, -94),
  GPoint(94, -92),
  GPoint(95, -92),
  GPoint(95, -7),
  GPoint(94, -7),
  GPoint(94, -5),
  GPoint(92, -5),
  GPoint(92, -4),
  GPoint(76, -4),
};

static const VectorContour s_slot_1_digit_4_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_4_contour_0_points), .points = (GPoint *)s_slot_1_digit_4_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_1_digit_5_contour_0_points[] = {
  GPoint(92, -95),
  GPoint(92, -94),
  GPoint(94, -94),
  GPoint(94, -92),
  GPoint(95, -92),
  GPoint(95, -76),
  GPoint(23, -76),
  GPoint(23, -59),
  GPoint(92, -59),
  GPoint(92, -58),
  GPoint(94, -58),
  GPoint(94, -56),
  GPoint(95, -56),
  GPoint(95, -7),
  GPoint(94, -7),
  GPoint(94, -5),
  GPoint(92, -5),
  GPoint(92, -4),
  GPoint(7, -4),
  GPoint(7, -5),
  GPoint(5, -5),
  GPoint(5, -7),
  GPoint(4, -7),
  GPoint(4, -23),
  GPoint(76, -23),
  GPoint(76, -40),
  GPoint(7, -40),
  GPoint(7, -41),
  GPoint(5, -41),
  GPoint(5, -43),
  GPoint(4, -43),
  GPoint(4, -92),
  GPoint(5, -92),
  GPoint(5, -94),
  GPoint(7, -94),
  GPoint(7, -95),
};

static const VectorContour s_slot_1_digit_5_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_5_contour_0_points), .points = (GPoint *)s_slot_1_digit_5_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_1_digit_6_contour_0_points[] = {
  GPoint(92, -95),
  GPoint(92, -94),
  GPoint(94, -94),
  GPoint(94, -92),
  GPoint(95, -92),
  GPoint(95, -76),
  GPoint(23, -76),
  GPoint(23, -59),
  GPoint(92, -59),
  GPoint(92, -58),
  GPoint(94, -58),
  GPoint(94, -56),
  GPoint(95, -56),
  GPoint(95, -7),
  GPoint(94, -7),
  GPoint(94, -5),
  GPoint(92, -5),
  GPoint(92, -4),
  GPoint(7, -4),
  GPoint(7, -5),
  GPoint(5, -5),
  GPoint(5, -7),
  GPoint(4, -7),
  GPoint(4, -92),
  GPoint(5, -92),
  GPoint(5, -94),
  GPoint(7, -94),
  GPoint(7, -95),
};

static const GPoint s_slot_1_digit_6_contour_1_points[] = {
  GPoint(23, -40),
  GPoint(23, -23),
  GPoint(76, -23),
  GPoint(76, -40),
};

static const VectorContour s_slot_1_digit_6_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_6_contour_0_points), .points = (GPoint *)s_slot_1_digit_6_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_6_contour_1_points), .points = (GPoint *)s_slot_1_digit_6_contour_1_points }, .is_hole = true },
};

static const GPoint s_slot_1_digit_7_contour_0_points[] = {
  GPoint(92, -95),
  GPoint(92, -94),
  GPoint(94, -94),
  GPoint(94, -92),
  GPoint(95, -92),
  GPoint(95, -7),
  GPoint(94, -7),
  GPoint(94, -5),
  GPoint(92, -5),
  GPoint(92, -4),
  GPoint(76, -4),
  GPoint(76, -76),
  GPoint(4, -76),
  GPoint(4, -92),
  GPoint(5, -92),
  GPoint(5, -94),
  GPoint(7, -94),
  GPoint(7, -95),
};

static const VectorContour s_slot_1_digit_7_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_7_contour_0_points), .points = (GPoint *)s_slot_1_digit_7_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_1_digit_8_contour_0_points[] = {
  GPoint(92, -95),
  GPoint(92, -94),
  GPoint(94, -94),
  GPoint(94, -92),
  GPoint(95, -92),
  GPoint(95, -7),
  GPoint(94, -7),
  GPoint(94, -5),
  GPoint(92, -5),
  GPoint(92, -4),
  GPoint(7, -4),
  GPoint(7, -5),
  GPoint(5, -5),
  GPoint(5, -7),
  GPoint(4, -7),
  GPoint(4, -92),
  GPoint(5, -92),
  GPoint(5, -94),
  GPoint(7, -94),
  GPoint(7, -95),
};

static const GPoint s_slot_1_digit_8_contour_1_points[] = {
  GPoint(23, -40),
  GPoint(23, -23),
  GPoint(76, -23),
  GPoint(76, -40),
};

static const GPoint s_slot_1_digit_8_contour_2_points[] = {
  GPoint(76, -59),
  GPoint(76, -76),
  GPoint(23, -76),
  GPoint(23, -59),
};

static const VectorContour s_slot_1_digit_8_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_8_contour_0_points), .points = (GPoint *)s_slot_1_digit_8_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_8_contour_1_points), .points = (GPoint *)s_slot_1_digit_8_contour_1_points }, .is_hole = true },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_8_contour_2_points), .points = (GPoint *)s_slot_1_digit_8_contour_2_points }, .is_hole = true },
};

static const GPoint s_slot_1_digit_9_contour_0_points[] = {
  GPoint(92, -95),
  GPoint(92, -94),
  GPoint(94, -94),
  GPoint(94, -92),
  GPoint(95, -92),
  GPoint(95, -7),
  GPoint(94, -7),
  GPoint(94, -5),
  GPoint(92, -5),
  GPoint(92, -4),
  GPoint(7, -4),
  GPoint(7, -5),
  GPoint(5, -5),
  GPoint(5, -7),
  GPoint(4, -7),
  GPoint(4, -23),
  GPoint(76, -23),
  GPoint(76, -40),
  GPoint(7, -40),
  GPoint(7, -41),
  GPoint(5, -41),
  GPoint(5, -43),
  GPoint(4, -43),
  GPoint(4, -92),
  GPoint(5, -92),
  GPoint(5, -94),
  GPoint(7, -94),
  GPoint(7, -95),
};

static const GPoint s_slot_1_digit_9_contour_1_points[] = {
  GPoint(76, -59),
  GPoint(76, -76),
  GPoint(23, -76),
  GPoint(23, -59),
};

static const VectorContour s_slot_1_digit_9_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_9_contour_0_points), .points = (GPoint *)s_slot_1_digit_9_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_9_contour_1_points), .points = (GPoint *)s_slot_1_digit_9_contour_1_points }, .is_hole = true },
};

static const GPoint s_slot_1_digit_10_contour_0_points[] = {
  GPoint(40, -76),
  GPoint(40, -95),
  GPoint(73, -95),
  GPoint(73, -94),
  GPoint(74, -94),
  GPoint(74, -92),
  GPoint(76, -92),
  GPoint(76, -7),
  GPoint(74, -7),
  GPoint(74, -5),
  GPoint(73, -5),
  GPoint(73, -4),
  GPoint(56, -4),
  GPoint(56, -76),
};

static const VectorContour s_slot_1_digit_10_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_1_digit_10_contour_0_points), .points = (GPoint *)s_slot_1_digit_10_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_2_digit_0_contour_0_points[] = {
  GPoint(-7, 4),
  GPoint(-7, 5),
  GPoint(-5, 5),
  GPoint(-5, 7),
  GPoint(-4, 7),
  GPoint(-4, 92),
  GPoint(-5, 92),
  GPoint(-5, 94),
  GPoint(-7, 94),
  GPoint(-7, 95),
  GPoint(-92, 95),
  GPoint(-92, 94),
  GPoint(-94, 94),
  GPoint(-94, 92),
  GPoint(-95, 92),
  GPoint(-95, 7),
  GPoint(-94, 7),
  GPoint(-94, 5),
  GPoint(-92, 5),
  GPoint(-92, 4),
};

static const GPoint s_slot_2_digit_0_contour_1_points[] = {
  GPoint(-76, 23),
  GPoint(-76, 76),
  GPoint(-23, 76),
  GPoint(-23, 23),
};

static const VectorContour s_slot_2_digit_0_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_0_contour_0_points), .points = (GPoint *)s_slot_2_digit_0_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_0_contour_1_points), .points = (GPoint *)s_slot_2_digit_0_contour_1_points }, .is_hole = true },
};

static const GPoint s_slot_2_digit_1_contour_0_points[] = {
  GPoint(-4, 92),
  GPoint(-5, 92),
  GPoint(-5, 94),
  GPoint(-7, 94),
  GPoint(-7, 95),
  GPoint(-23, 95),
  GPoint(-23, 23),
  GPoint(-40, 23),
  GPoint(-40, 4),
  GPoint(-7, 4),
  GPoint(-7, 5),
  GPoint(-5, 5),
  GPoint(-5, 7),
  GPoint(-4, 7),
};

static const VectorContour s_slot_2_digit_1_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_1_contour_0_points), .points = (GPoint *)s_slot_2_digit_1_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_2_digit_2_contour_0_points[] = {
  GPoint(-7, 4),
  GPoint(-7, 5),
  GPoint(-5, 5),
  GPoint(-5, 7),
  GPoint(-4, 7),
  GPoint(-4, 56),
  GPoint(-5, 56),
  GPoint(-5, 58),
  GPoint(-7, 58),
  GPoint(-7, 59),
  GPoint(-76, 59),
  GPoint(-76, 76),
  GPoint(-4, 76),
  GPoint(-4, 92),
  GPoint(-5, 92),
  GPoint(-5, 94),
  GPoint(-7, 94),
  GPoint(-7, 95),
  GPoint(-92, 95),
  GPoint(-92, 94),
  GPoint(-94, 94),
  GPoint(-94, 92),
  GPoint(-95, 92),
  GPoint(-95, 43),
  GPoint(-94, 43),
  GPoint(-94, 41),
  GPoint(-92, 41),
  GPoint(-92, 40),
  GPoint(-23, 40),
  GPoint(-23, 23),
  GPoint(-95, 23),
  GPoint(-95, 7),
  GPoint(-94, 7),
  GPoint(-94, 5),
  GPoint(-92, 5),
  GPoint(-92, 4),
};

static const VectorContour s_slot_2_digit_2_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_2_contour_0_points), .points = (GPoint *)s_slot_2_digit_2_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_2_digit_3_contour_0_points[] = {
  GPoint(-7, 4),
  GPoint(-7, 5),
  GPoint(-5, 5),
  GPoint(-5, 7),
  GPoint(-4, 7),
  GPoint(-4, 92),
  GPoint(-5, 92),
  GPoint(-5, 94),
  GPoint(-7, 94),
  GPoint(-7, 95),
  GPoint(-92, 95),
  GPoint(-92, 94),
  GPoint(-94, 94),
  GPoint(-94, 92),
  GPoint(-95, 92),
  GPoint(-95, 76),
  GPoint(-23, 76),
  GPoint(-23, 59),
  GPoint(-76, 59),
  GPoint(-76, 40),
  GPoint(-23, 40),
  GPoint(-23, 23),
  GPoint(-95, 23),
  GPoint(-95, 7),
  GPoint(-94, 7),
  GPoint(-94, 5),
  GPoint(-92, 5),
  GPoint(-92, 4),
};

static const VectorContour s_slot_2_digit_3_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_3_contour_0_points), .points = (GPoint *)s_slot_2_digit_3_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_2_digit_4_contour_0_points[] = {
  GPoint(-23, 59),
  GPoint(-92, 59),
  GPoint(-92, 58),
  GPoint(-94, 58),
  GPoint(-94, 56),
  GPoint(-95, 56),
  GPoint(-95, 7),
  GPoint(-94, 7),
  GPoint(-94, 5),
  GPoint(-92, 5),
  GPoint(-92, 4),
  GPoint(-76, 4),
  GPoint(-76, 40),
  GPoint(-23, 40),
  GPoint(-23, 4),
  GPoint(-7, 4),
  GPoint(-7, 5),
  GPoint(-5, 5),
  GPoint(-5, 7),
  GPoint(-4, 7),
  GPoint(-4, 92),
  GPoint(-5, 92),
  GPoint(-5, 94),
  GPoint(-7, 94),
  GPoint(-7, 95),
  GPoint(-23, 95),
};

static const VectorContour s_slot_2_digit_4_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_4_contour_0_points), .points = (GPoint *)s_slot_2_digit_4_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_2_digit_5_contour_0_points[] = {
  GPoint(-7, 4),
  GPoint(-7, 5),
  GPoint(-5, 5),
  GPoint(-5, 7),
  GPoint(-4, 7),
  GPoint(-4, 23),
  GPoint(-76, 23),
  GPoint(-76, 40),
  GPoint(-7, 40),
  GPoint(-7, 41),
  GPoint(-5, 41),
  GPoint(-5, 43),
  GPoint(-4, 43),
  GPoint(-4, 92),
  GPoint(-5, 92),
  GPoint(-5, 94),
  GPoint(-7, 94),
  GPoint(-7, 95),
  GPoint(-92, 95),
  GPoint(-92, 94),
  GPoint(-94, 94),
  GPoint(-94, 92),
  GPoint(-95, 92),
  GPoint(-95, 76),
  GPoint(-23, 76),
  GPoint(-23, 59),
  GPoint(-92, 59),
  GPoint(-92, 58),
  GPoint(-94, 58),
  GPoint(-94, 56),
  GPoint(-95, 56),
  GPoint(-95, 7),
  GPoint(-94, 7),
  GPoint(-94, 5),
  GPoint(-92, 5),
  GPoint(-92, 4),
};

static const VectorContour s_slot_2_digit_5_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_5_contour_0_points), .points = (GPoint *)s_slot_2_digit_5_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_2_digit_6_contour_0_points[] = {
  GPoint(-7, 4),
  GPoint(-7, 5),
  GPoint(-5, 5),
  GPoint(-5, 7),
  GPoint(-4, 7),
  GPoint(-4, 23),
  GPoint(-76, 23),
  GPoint(-76, 40),
  GPoint(-7, 40),
  GPoint(-7, 41),
  GPoint(-5, 41),
  GPoint(-5, 43),
  GPoint(-4, 43),
  GPoint(-4, 92),
  GPoint(-5, 92),
  GPoint(-5, 94),
  GPoint(-7, 94),
  GPoint(-7, 95),
  GPoint(-92, 95),
  GPoint(-92, 94),
  GPoint(-94, 94),
  GPoint(-94, 92),
  GPoint(-95, 92),
  GPoint(-95, 7),
  GPoint(-94, 7),
  GPoint(-94, 5),
  GPoint(-92, 5),
  GPoint(-92, 4),
};

static const GPoint s_slot_2_digit_6_contour_1_points[] = {
  GPoint(-76, 59),
  GPoint(-76, 76),
  GPoint(-23, 76),
  GPoint(-23, 59),
};

static const VectorContour s_slot_2_digit_6_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_6_contour_0_points), .points = (GPoint *)s_slot_2_digit_6_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_6_contour_1_points), .points = (GPoint *)s_slot_2_digit_6_contour_1_points }, .is_hole = true },
};

static const GPoint s_slot_2_digit_7_contour_0_points[] = {
  GPoint(-7, 4),
  GPoint(-7, 5),
  GPoint(-5, 5),
  GPoint(-5, 7),
  GPoint(-4, 7),
  GPoint(-4, 92),
  GPoint(-5, 92),
  GPoint(-5, 94),
  GPoint(-7, 94),
  GPoint(-7, 95),
  GPoint(-23, 95),
  GPoint(-23, 23),
  GPoint(-95, 23),
  GPoint(-95, 7),
  GPoint(-94, 7),
  GPoint(-94, 5),
  GPoint(-92, 5),
  GPoint(-92, 4),
};

static const VectorContour s_slot_2_digit_7_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_7_contour_0_points), .points = (GPoint *)s_slot_2_digit_7_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_2_digit_8_contour_0_points[] = {
  GPoint(-7, 4),
  GPoint(-7, 5),
  GPoint(-5, 5),
  GPoint(-5, 7),
  GPoint(-4, 7),
  GPoint(-4, 92),
  GPoint(-5, 92),
  GPoint(-5, 94),
  GPoint(-7, 94),
  GPoint(-7, 95),
  GPoint(-92, 95),
  GPoint(-92, 94),
  GPoint(-94, 94),
  GPoint(-94, 92),
  GPoint(-95, 92),
  GPoint(-95, 7),
  GPoint(-94, 7),
  GPoint(-94, 5),
  GPoint(-92, 5),
  GPoint(-92, 4),
};

static const GPoint s_slot_2_digit_8_contour_1_points[] = {
  GPoint(-76, 59),
  GPoint(-76, 76),
  GPoint(-23, 76),
  GPoint(-23, 59),
};

static const GPoint s_slot_2_digit_8_contour_2_points[] = {
  GPoint(-23, 40),
  GPoint(-23, 23),
  GPoint(-76, 23),
  GPoint(-76, 40),
};

static const VectorContour s_slot_2_digit_8_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_8_contour_0_points), .points = (GPoint *)s_slot_2_digit_8_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_8_contour_1_points), .points = (GPoint *)s_slot_2_digit_8_contour_1_points }, .is_hole = true },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_8_contour_2_points), .points = (GPoint *)s_slot_2_digit_8_contour_2_points }, .is_hole = true },
};

static const GPoint s_slot_2_digit_9_contour_0_points[] = {
  GPoint(-7, 4),
  GPoint(-7, 5),
  GPoint(-5, 5),
  GPoint(-5, 7),
  GPoint(-4, 7),
  GPoint(-4, 92),
  GPoint(-5, 92),
  GPoint(-5, 94),
  GPoint(-7, 94),
  GPoint(-7, 95),
  GPoint(-92, 95),
  GPoint(-92, 94),
  GPoint(-94, 94),
  GPoint(-94, 92),
  GPoint(-95, 92),
  GPoint(-95, 76),
  GPoint(-23, 76),
  GPoint(-23, 59),
  GPoint(-92, 59),
  GPoint(-92, 58),
  GPoint(-94, 58),
  GPoint(-94, 56),
  GPoint(-95, 56),
  GPoint(-95, 7),
  GPoint(-94, 7),
  GPoint(-94, 5),
  GPoint(-92, 5),
  GPoint(-92, 4),
};

static const GPoint s_slot_2_digit_9_contour_1_points[] = {
  GPoint(-23, 40),
  GPoint(-23, 23),
  GPoint(-76, 23),
  GPoint(-76, 40),
};

static const VectorContour s_slot_2_digit_9_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_9_contour_0_points), .points = (GPoint *)s_slot_2_digit_9_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_9_contour_1_points), .points = (GPoint *)s_slot_2_digit_9_contour_1_points }, .is_hole = true },
};

static const GPoint s_slot_2_digit_10_contour_0_points[] = {
  GPoint(-59, 23),
  GPoint(-59, 4),
  GPoint(-26, 4),
  GPoint(-26, 5),
  GPoint(-25, 5),
  GPoint(-25, 7),
  GPoint(-23, 7),
  GPoint(-23, 92),
  GPoint(-25, 92),
  GPoint(-25, 94),
  GPoint(-26, 94),
  GPoint(-26, 95),
  GPoint(-43, 95),
  GPoint(-43, 23),
};

static const VectorContour s_slot_2_digit_10_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_2_digit_10_contour_0_points), .points = (GPoint *)s_slot_2_digit_10_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_3_digit_0_contour_0_points[] = {
  GPoint(92, 4),
  GPoint(92, 5),
  GPoint(94, 5),
  GPoint(94, 7),
  GPoint(95, 7),
  GPoint(95, 92),
  GPoint(94, 92),
  GPoint(94, 94),
  GPoint(92, 94),
  GPoint(92, 95),
  GPoint(7, 95),
  GPoint(7, 94),
  GPoint(5, 94),
  GPoint(5, 92),
  GPoint(4, 92),
  GPoint(4, 7),
  GPoint(5, 7),
  GPoint(5, 5),
  GPoint(7, 5),
  GPoint(7, 4),
};

static const GPoint s_slot_3_digit_0_contour_1_points[] = {
  GPoint(23, 23),
  GPoint(23, 76),
  GPoint(76, 76),
  GPoint(76, 23),
};

static const VectorContour s_slot_3_digit_0_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_0_contour_0_points), .points = (GPoint *)s_slot_3_digit_0_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_0_contour_1_points), .points = (GPoint *)s_slot_3_digit_0_contour_1_points }, .is_hole = true },
};

static const GPoint s_slot_3_digit_1_contour_0_points[] = {
  GPoint(95, 92),
  GPoint(94, 92),
  GPoint(94, 94),
  GPoint(92, 94),
  GPoint(92, 95),
  GPoint(76, 95),
  GPoint(76, 23),
  GPoint(59, 23),
  GPoint(59, 4),
  GPoint(92, 4),
  GPoint(92, 5),
  GPoint(94, 5),
  GPoint(94, 7),
  GPoint(95, 7),
};

static const VectorContour s_slot_3_digit_1_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_1_contour_0_points), .points = (GPoint *)s_slot_3_digit_1_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_3_digit_2_contour_0_points[] = {
  GPoint(92, 4),
  GPoint(92, 5),
  GPoint(94, 5),
  GPoint(94, 7),
  GPoint(95, 7),
  GPoint(95, 56),
  GPoint(94, 56),
  GPoint(94, 58),
  GPoint(92, 58),
  GPoint(92, 59),
  GPoint(23, 59),
  GPoint(23, 76),
  GPoint(95, 76),
  GPoint(95, 92),
  GPoint(94, 92),
  GPoint(94, 94),
  GPoint(92, 94),
  GPoint(92, 95),
  GPoint(7, 95),
  GPoint(7, 94),
  GPoint(5, 94),
  GPoint(5, 92),
  GPoint(4, 92),
  GPoint(4, 43),
  GPoint(5, 43),
  GPoint(5, 41),
  GPoint(7, 41),
  GPoint(7, 40),
  GPoint(76, 40),
  GPoint(76, 23),
  GPoint(4, 23),
  GPoint(4, 7),
  GPoint(5, 7),
  GPoint(5, 5),
  GPoint(7, 5),
  GPoint(7, 4),
};

static const VectorContour s_slot_3_digit_2_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_2_contour_0_points), .points = (GPoint *)s_slot_3_digit_2_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_3_digit_3_contour_0_points[] = {
  GPoint(92, 4),
  GPoint(92, 5),
  GPoint(94, 5),
  GPoint(94, 7),
  GPoint(95, 7),
  GPoint(95, 92),
  GPoint(94, 92),
  GPoint(94, 94),
  GPoint(92, 94),
  GPoint(92, 95),
  GPoint(7, 95),
  GPoint(7, 94),
  GPoint(5, 94),
  GPoint(5, 92),
  GPoint(4, 92),
  GPoint(4, 76),
  GPoint(76, 76),
  GPoint(76, 59),
  GPoint(23, 59),
  GPoint(23, 40),
  GPoint(76, 40),
  GPoint(76, 23),
  GPoint(4, 23),
  GPoint(4, 7),
  GPoint(5, 7),
  GPoint(5, 5),
  GPoint(7, 5),
  GPoint(7, 4),
};

static const VectorContour s_slot_3_digit_3_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_3_contour_0_points), .points = (GPoint *)s_slot_3_digit_3_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_3_digit_4_contour_0_points[] = {
  GPoint(76, 59),
  GPoint(7, 59),
  GPoint(7, 58),
  GPoint(5, 58),
  GPoint(5, 56),
  GPoint(4, 56),
  GPoint(4, 7),
  GPoint(5, 7),
  GPoint(5, 5),
  GPoint(7, 5),
  GPoint(7, 4),
  GPoint(23, 4),
  GPoint(23, 40),
  GPoint(76, 40),
  GPoint(76, 4),
  GPoint(92, 4),
  GPoint(92, 5),
  GPoint(94, 5),
  GPoint(94, 7),
  GPoint(95, 7),
  GPoint(95, 92),
  GPoint(94, 92),
  GPoint(94, 94),
  GPoint(92, 94),
  GPoint(92, 95),
  GPoint(76, 95),
};

static const VectorContour s_slot_3_digit_4_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_4_contour_0_points), .points = (GPoint *)s_slot_3_digit_4_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_3_digit_5_contour_0_points[] = {
  GPoint(92, 4),
  GPoint(92, 5),
  GPoint(94, 5),
  GPoint(94, 7),
  GPoint(95, 7),
  GPoint(95, 23),
  GPoint(23, 23),
  GPoint(23, 40),
  GPoint(92, 40),
  GPoint(92, 41),
  GPoint(94, 41),
  GPoint(94, 43),
  GPoint(95, 43),
  GPoint(95, 92),
  GPoint(94, 92),
  GPoint(94, 94),
  GPoint(92, 94),
  GPoint(92, 95),
  GPoint(7, 95),
  GPoint(7, 94),
  GPoint(5, 94),
  GPoint(5, 92),
  GPoint(4, 92),
  GPoint(4, 76),
  GPoint(76, 76),
  GPoint(76, 59),
  GPoint(7, 59),
  GPoint(7, 58),
  GPoint(5, 58),
  GPoint(5, 56),
  GPoint(4, 56),
  GPoint(4, 7),
  GPoint(5, 7),
  GPoint(5, 5),
  GPoint(7, 5),
  GPoint(7, 4),
};

static const VectorContour s_slot_3_digit_5_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_5_contour_0_points), .points = (GPoint *)s_slot_3_digit_5_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_3_digit_6_contour_0_points[] = {
  GPoint(92, 4),
  GPoint(92, 5),
  GPoint(94, 5),
  GPoint(94, 7),
  GPoint(95, 7),
  GPoint(95, 23),
  GPoint(23, 23),
  GPoint(23, 40),
  GPoint(92, 40),
  GPoint(92, 41),
  GPoint(94, 41),
  GPoint(94, 43),
  GPoint(95, 43),
  GPoint(95, 92),
  GPoint(94, 92),
  GPoint(94, 94),
  GPoint(92, 94),
  GPoint(92, 95),
  GPoint(7, 95),
  GPoint(7, 94),
  GPoint(5, 94),
  GPoint(5, 92),
  GPoint(4, 92),
  GPoint(4, 7),
  GPoint(5, 7),
  GPoint(5, 5),
  GPoint(7, 5),
  GPoint(7, 4),
};

static const GPoint s_slot_3_digit_6_contour_1_points[] = {
  GPoint(23, 59),
  GPoint(23, 76),
  GPoint(76, 76),
  GPoint(76, 59),
};

static const VectorContour s_slot_3_digit_6_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_6_contour_0_points), .points = (GPoint *)s_slot_3_digit_6_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_6_contour_1_points), .points = (GPoint *)s_slot_3_digit_6_contour_1_points }, .is_hole = true },
};

static const GPoint s_slot_3_digit_7_contour_0_points[] = {
  GPoint(92, 4),
  GPoint(92, 5),
  GPoint(94, 5),
  GPoint(94, 7),
  GPoint(95, 7),
  GPoint(95, 92),
  GPoint(94, 92),
  GPoint(94, 94),
  GPoint(92, 94),
  GPoint(92, 95),
  GPoint(76, 95),
  GPoint(76, 23),
  GPoint(4, 23),
  GPoint(4, 7),
  GPoint(5, 7),
  GPoint(5, 5),
  GPoint(7, 5),
  GPoint(7, 4),
};

static const VectorContour s_slot_3_digit_7_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_7_contour_0_points), .points = (GPoint *)s_slot_3_digit_7_contour_0_points }, .is_hole = false },
};

static const GPoint s_slot_3_digit_8_contour_0_points[] = {
  GPoint(92, 4),
  GPoint(92, 5),
  GPoint(94, 5),
  GPoint(94, 7),
  GPoint(95, 7),
  GPoint(95, 92),
  GPoint(94, 92),
  GPoint(94, 94),
  GPoint(92, 94),
  GPoint(92, 95),
  GPoint(7, 95),
  GPoint(7, 94),
  GPoint(5, 94),
  GPoint(5, 92),
  GPoint(4, 92),
  GPoint(4, 7),
  GPoint(5, 7),
  GPoint(5, 5),
  GPoint(7, 5),
  GPoint(7, 4),
};

static const GPoint s_slot_3_digit_8_contour_1_points[] = {
  GPoint(23, 59),
  GPoint(23, 76),
  GPoint(76, 76),
  GPoint(76, 59),
};

static const GPoint s_slot_3_digit_8_contour_2_points[] = {
  GPoint(76, 40),
  GPoint(76, 23),
  GPoint(23, 23),
  GPoint(23, 40),
};

static const VectorContour s_slot_3_digit_8_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_8_contour_0_points), .points = (GPoint *)s_slot_3_digit_8_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_8_contour_1_points), .points = (GPoint *)s_slot_3_digit_8_contour_1_points }, .is_hole = true },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_8_contour_2_points), .points = (GPoint *)s_slot_3_digit_8_contour_2_points }, .is_hole = true },
};

static const GPoint s_slot_3_digit_9_contour_0_points[] = {
  GPoint(92, 4),
  GPoint(92, 5),
  GPoint(94, 5),
  GPoint(94, 7),
  GPoint(95, 7),
  GPoint(95, 92),
  GPoint(94, 92),
  GPoint(94, 94),
  GPoint(92, 94),
  GPoint(92, 95),
  GPoint(7, 95),
  GPoint(7, 94),
  GPoint(5, 94),
  GPoint(5, 92),
  GPoint(4, 92),
  GPoint(4, 76),
  GPoint(76, 76),
  GPoint(76, 59),
  GPoint(7, 59),
  GPoint(7, 58),
  GPoint(5, 58),
  GPoint(5, 56),
  GPoint(4, 56),
  GPoint(4, 7),
  GPoint(5, 7),
  GPoint(5, 5),
  GPoint(7, 5),
  GPoint(7, 4),
};

static const GPoint s_slot_3_digit_9_contour_1_points[] = {
  GPoint(76, 40),
  GPoint(76, 23),
  GPoint(23, 23),
  GPoint(23, 40),
};

static const VectorContour s_slot_3_digit_9_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_9_contour_0_points), .points = (GPoint *)s_slot_3_digit_9_contour_0_points }, .is_hole = false },
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_9_contour_1_points), .points = (GPoint *)s_slot_3_digit_9_contour_1_points }, .is_hole = true },
};

static const GPoint s_slot_3_digit_10_contour_0_points[] = {
  GPoint(40, 23),
  GPoint(40, 4),
  GPoint(73, 4),
  GPoint(73, 5),
  GPoint(74, 5),
  GPoint(74, 7),
  GPoint(76, 7),
  GPoint(76, 92),
  GPoint(74, 92),
  GPoint(74, 94),
  GPoint(73, 94),
  GPoint(73, 95),
  GPoint(56, 95),
  GPoint(56, 23),
};

static const VectorContour s_slot_3_digit_10_contours[] = {
  { .path_info = { .num_points = ARRAY_LENGTH(s_slot_3_digit_10_contour_0_points), .points = (GPoint *)s_slot_3_digit_10_contour_0_points }, .is_hole = false },
};

static const VectorGlyph s_vector_glyphs[4][11] = {{
  [0] = {
    [0] = { .contours = s_slot_0_digit_0_contours, .contour_count = 2 },
    [1] = { .contours = s_slot_0_digit_1_contours, .contour_count = 1 },
    [2] = { .contours = s_slot_0_digit_2_contours, .contour_count = 1 },
    [3] = { .contours = s_slot_0_digit_3_contours, .contour_count = 1 },
    [4] = { .contours = s_slot_0_digit_4_contours, .contour_count = 1 },
    [5] = { .contours = s_slot_0_digit_5_contours, .contour_count = 1 },
    [6] = { .contours = s_slot_0_digit_6_contours, .contour_count = 2 },
    [7] = { .contours = s_slot_0_digit_7_contours, .contour_count = 1 },
    [8] = { .contours = s_slot_0_digit_8_contours, .contour_count = 3 },
    [9] = { .contours = s_slot_0_digit_9_contours, .contour_count = 2 },
    [10] = { .contours = s_slot_0_digit_10_contours, .contour_count = 1 },
  },
  [1] = {
    [0] = { .contours = s_slot_1_digit_0_contours, .contour_count = 2 },
    [1] = { .contours = s_slot_1_digit_1_contours, .contour_count = 1 },
    [2] = { .contours = s_slot_1_digit_2_contours, .contour_count = 1 },
    [3] = { .contours = s_slot_1_digit_3_contours, .contour_count = 1 },
    [4] = { .contours = s_slot_1_digit_4_contours, .contour_count = 1 },
    [5] = { .contours = s_slot_1_digit_5_contours, .contour_count = 1 },
    [6] = { .contours = s_slot_1_digit_6_contours, .contour_count = 2 },
    [7] = { .contours = s_slot_1_digit_7_contours, .contour_count = 1 },
    [8] = { .contours = s_slot_1_digit_8_contours, .contour_count = 3 },
    [9] = { .contours = s_slot_1_digit_9_contours, .contour_count = 2 },
    [10] = { .contours = s_slot_1_digit_10_contours, .contour_count = 1 },
  },
  [2] = {
    [0] = { .contours = s_slot_2_digit_0_contours, .contour_count = 2 },
    [1] = { .contours = s_slot_2_digit_1_contours, .contour_count = 1 },
    [2] = { .contours = s_slot_2_digit_2_contours, .contour_count = 1 },
    [3] = { .contours = s_slot_2_digit_3_contours, .contour_count = 1 },
    [4] = { .contours = s_slot_2_digit_4_contours, .contour_count = 1 },
    [5] = { .contours = s_slot_2_digit_5_contours, .contour_count = 1 },
    [6] = { .contours = s_slot_2_digit_6_contours, .contour_count = 2 },
    [7] = { .contours = s_slot_2_digit_7_contours, .contour_count = 1 },
    [8] = { .contours = s_slot_2_digit_8_contours, .contour_count = 3 },
    [9] = { .contours = s_slot_2_digit_9_contours, .contour_count = 2 },
    [10] = { .contours = s_slot_2_digit_10_contours, .contour_count = 1 },
  },
  [3] = {
    [0] = { .contours = s_slot_3_digit_0_contours, .contour_count = 2 },
    [1] = { .contours = s_slot_3_digit_1_contours, .contour_count = 1 },
    [2] = { .contours = s_slot_3_digit_2_contours, .contour_count = 1 },
    [3] = { .contours = s_slot_3_digit_3_contours, .contour_count = 1 },
    [4] = { .contours = s_slot_3_digit_4_contours, .contour_count = 1 },
    [5] = { .contours = s_slot_3_digit_5_contours, .contour_count = 1 },
    [6] = { .contours = s_slot_3_digit_6_contours, .contour_count = 2 },
    [7] = { .contours = s_slot_3_digit_7_contours, .contour_count = 1 },
    [8] = { .contours = s_slot_3_digit_8_contours, .contour_count = 3 },
    [9] = { .contours = s_slot_3_digit_9_contours, .contour_count = 2 },
    [10] = { .contours = s_slot_3_digit_10_contours, .contour_count = 1 },
  },
};

#endif
