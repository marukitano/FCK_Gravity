#ifndef T2_VECTOR_TEST_H
#define T2_VECTOR_TEST_H

#include <pebble.h>

#define T2_VECTOR_CENTER_X 100
#define T2_VECTOR_CENTER_Y 100
#define T2_VECTOR_CONTOUR_COUNT 1

typedef struct {
  GPathInfo path_info;
  bool is_hole;
} T2VectorContour;

static GPoint s_t2_contour_0_points[] = {
  GPoint(-72, -72),
  GPoint(-73, -71),
  GPoint(-73, -70),
  GPoint(-74, -69),
  GPoint(-74, -63),
  GPoint(-75, -62),
  GPoint(-75, -43),
  GPoint(43, -43),
  GPoint(43, -16),
  GPoint(-46, -16),
  GPoint(-52, -15),
  GPoint(-65, -15),
  GPoint(-68, -14),
  GPoint(-71, -14),
  GPoint(-72, -13),
  GPoint(-73, -11),
  GPoint(-74, -6),
  GPoint(-74, 1),
  GPoint(-75, 10),
  GPoint(-75, 49),
  GPoint(-74, 58),
  GPoint(-74, 65),
  GPoint(-73, 70),
  GPoint(-72, 72),
  GPoint(-69, 73),
  GPoint(-60, 74),
  GPoint(-48, 74),
  GPoint(-34, 75),
  GPoint(34, 75),
  GPoint(48, 74),
  GPoint(60, 74),
  GPoint(69, 73),
  GPoint(72, 72),
  GPoint(73, 71),
  GPoint(73, 70),
  GPoint(74, 69),
  GPoint(74, 63),
  GPoint(75, 62),
  GPoint(75, 43),
  GPoint(-43, 43),
  GPoint(-43, 16),
  GPoint(46, 16),
  GPoint(52, 15),
  GPoint(65, 15),
  GPoint(68, 14),
  GPoint(71, 14),
  GPoint(72, 13),
  GPoint(73, 11),
  GPoint(74, 6),
  GPoint(74, -1),
  GPoint(75, -10),
  GPoint(75, -49),
  GPoint(74, -58),
  GPoint(74, -65),
  GPoint(73, -70),
  GPoint(72, -72),
  GPoint(69, -73),
  GPoint(60, -74),
  GPoint(48, -74),
  GPoint(34, -75),
  GPoint(-34, -75),
  GPoint(-48, -74),
  GPoint(-60, -74),
  GPoint(-69, -73),
};

static T2VectorContour T2_VECTOR_CONTOURS[] = {
  {
    .path_info = {
      .num_points = ARRAY_LENGTH(s_t2_contour_0_points),
      .points = s_t2_contour_0_points,
    },
    .is_hole = false,
  },
};

#endif
