#include "number.h"
#include <stdio.h>
#include <stdlib.h>

Number new_number(unsigned short number, Vector2 position) {
	char buffer[6];

	Number num;
	num.len = snprintf(buffer, sizeof(buffer), "%d", number);
	num.digits = (Digit *)malloc(sizeof(Digit) * num.len);

	float gap = 200.0f;

	float width = (num.len - 1) * gap;
	float start_x = position.x - (width / 2.0f);

	for (int i = 0; i < num.len; i++) {
		int digit_index = buffer[i] - '0';

		Vector2 pos = {start_x + (i * gap), position.y};

		num.digits[i] = new_digit(pos, digits[digit_index]);
	}

	return num;
}

void draw_number(Number *num) {
	for (int i = 0; i < num->len; i++) {
		draw_digit(&num->digits[i]);
	}
}

void free_number(Number *num) { free(num->digits); }
