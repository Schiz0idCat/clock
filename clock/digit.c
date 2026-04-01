#include "digit.h"
#include "../tools/math/my_math.h"

const int DIGIT_MAP[NUMBERS][SEGMENTS_LEN] = {ZERO, ONE, TWO,	THREE, FOUR,
											  FIVE, SIX, SEVEN, EIGHT, NINE};

Digit new_digit(Vector2 position) {
	Vector2 a, b, c, d, e, f, g;
	Digit digit;

	float ox = position.x;
	float oy = position.y;
	float L = SEG_LENGTH;

	float gap = 2.5f;

	a = (Vector2){ox, oy - L * gap};					   // up
	b = (Vector2){ox - (L / 2) * gap, oy - (L / 2) * gap}; // up left
	c = (Vector2){ox + (L / 2) * gap, oy - (L / 2) * gap}; // up right
	d = (Vector2){ox, oy};								   // middle
	e = (Vector2){ox - (L / 2) * gap, oy + (L / 2) * gap}; // down left
	f = (Vector2){ox + (L / 2) * gap, oy + (L / 2) * gap}; // down right
	g = (Vector2){ox, oy + L * gap};					   // down

	digit.position = position;

	digit.segments[0] = new_segment(a, deg2rad(180));
	digit.segments[1] = new_segment(b, deg2rad(90));
	digit.segments[2] = new_segment(c, deg2rad(90));
	digit.segments[3] = new_segment(d, deg2rad(180));
	digit.segments[4] = new_segment(e, deg2rad(90));
	digit.segments[5] = new_segment(f, deg2rad(90));
	digit.segments[6] = new_segment(g, deg2rad(180));

	return digit;
}

void draw_digit(Digit *digit) {
	for (int i = 0; i < SEGMENTS_LEN; i++) {
		draw_segment(&digit->segments[i]);
	}
}
