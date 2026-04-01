#ifndef DIGIT_H
#define DIGIT_H

#include "segment.h"
#include <raylib.h>

#define SEGMENTS_LEN 7
#define DIGITS_LEN 10

extern const char digits[DIGITS_LEN][SEGMENTS_LEN];

typedef struct {
	Segment segments[SEGMENTS_LEN];
	Vector2 position;
} Digit;

Digit new_digit(Vector2 position, const char number[SEGMENTS_LEN]);
void draw_digit(Digit *digit);

#endif
