#ifndef SEGMENT_H
#define SEGMENT_H

#include <raylib.h>

typedef struct Segment {
  Vector2 center;
  float angle;
  int length;
  int thickness;
} Segment;

#define ON RED

Segment new_segment(Vector2 center, float angle);
void draw_segment(Segment *segment);

#endif
