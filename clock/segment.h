#ifndef SEGMENT_H
#define SEGMENT_H

#include <raylib.h>

typedef struct Segment {
	Vector2 position;
	float angle;
	int length;
	int thickness;
} Segment;

#define ON RED

extern const int WIDTH;
extern const int HEIGHT;

#define SEG_LENGTH HEIGHT * 0.15f
#define SEG_THICKNESS WIDTH * 0.01f

Segment new_segment(Vector2 position, float angle);
void draw_segment(Segment *segment);

#endif
