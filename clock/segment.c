#include "segment.h"
#include <math.h>

extern const int WIDTH;
extern const int HEIGHT;

Segment new_segment(Vector2 center, float angle) {
  int length = HEIGHT * 0.4f;
  int thickness = WIDTH * 0.01f;

  return (Segment){center, angle, length, thickness};
}

void draw_segment(Segment *segment) {
  float x = segment->position.x;
  float y = segment->position.y;
  int l = segment->length;
  int t = segment->thickness;

  float cosA = cosf(-segment->angle);
  float sinA = sinf(-segment->angle);

  Vector2 dir = (Vector2){cosA, sinA};
  Vector2 perp = (Vector2){-sinA, cosA};

  char len = 6;
  Vector2 points[] = {{x - dir.x * (l + t), y - dir.y * (l + t)},

                      {x - dir.x * l + perp.x * t, y - dir.y * l + perp.y * t},
                      {x - dir.x * l - perp.x * t, y - dir.y * l - perp.y * t},

                      {x + dir.x * l + perp.x * t, y + dir.y * l + perp.y * t},
                      {x + dir.x * l - perp.x * t, y + dir.y * l - perp.y * t},

                      {x + dir.x * (l + t), y + dir.y * (l + t)}};

  DrawTriangleStrip(points, len, ON);
}
