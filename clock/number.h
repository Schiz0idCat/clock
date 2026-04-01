#ifndef NUMBER_H
#define NUMBER_H

#include "digit.h"
#include <raylib.h>

typedef struct {
	Digit *digits;
	Vector2 position;
	char len;
} Number;

Number new_number(unsigned short number, Vector2 position);
void draw_number(Number *num);
void free_number(Number *num);

#endif
