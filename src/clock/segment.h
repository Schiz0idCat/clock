#ifndef SEGMENT_H
#define SEGMENT_H

#include "raylib.h"

typedef struct Segment {
	Vector2 position;
	float angle;
	int length;
	int thickness;
	bool on;
} Segment;

#define ON RED
#define OFF DARKGRAY

extern const int WIDTH;
extern const int HEIGHT;

#define SEG_LENGTH HEIGHT * 0.15f
#define SEG_THICKNESS WIDTH * 0.01f

Segment new_segment(Vector2 position, float angle, bool on);
void draw_segment(Segment *segment);

#endif
