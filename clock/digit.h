#ifndef DIGIT_H
#define DIGIT_H

#include "segment.h"
#include <raylib.h>

#define SEGMENTS_LEN 7
#define NUMBERS 10

#define ZERO {1, 1, 1, 0, 1, 1, 1}
#define ONE {0, 0, 1, 0, 0, 1, 0}
#define TWO {1, 0, 1, 1, 1, 0, 1}
#define THREE {1, 0, 1, 1, 0, 1, 1}
#define FOUR {0, 1, 1, 1, 0, 1, 0}
#define FIVE {1, 1, 0, 1, 0, 1, 1}
#define SIX {1, 1, 0, 1, 1, 1, 1}
#define SEVEN {1, 0, 1, 0, 0, 1, 0}
#define EIGHT {1, 1, 1, 1, 1, 1, 1}
#define NINE {1, 1, 1, 1, 0, 1, 1}

typedef struct {
	Segment segments[SEGMENTS_LEN];
	Vector2 position;
} Digit;

Digit new_digit(Vector2 position);
void draw_digit(Digit *digit);

#endif
