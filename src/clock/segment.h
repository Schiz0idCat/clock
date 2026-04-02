#ifndef SEGMENT_H
#define SEGMENT_H

#include "raylib.h"
#include <math.h>

typedef struct Segment {
	Vector2 position;
	float angle;
	int length;
	int thickness;
	bool on;
} Segment;

#define ON RED
#define OFF (Color){40, 40, 40, 255}

#define SCALE_UNIT fminf(GetScreenWidth() / 1500.0f, GetScreenHeight() / 400.0f)
#define SEG_LENGTH (60.0f * SCALE_UNIT)
#define SEG_THICKNESS (10.0f * SCALE_UNIT)

Segment new_segment(Vector2 position, float angle, bool on);
void draw_segment(Segment *segment);

#endif
