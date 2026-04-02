#include "number.h"
#include <stdio.h>
#include <stdlib.h>

#define GAP SEG_LENGTH * 3.2f

Number new_number(unsigned short number, Vector2 position) {
	char buffer[6];

	Number num;
	num.len = snprintf(buffer, sizeof(buffer), "%d", number);
	num.digits = (Digit *)malloc(sizeof(Digit) * num.len);

	float width = (num.len - 1) * GAP;
	float start_x = position.x - (width / 2.0f);

	for (int i = 0; i < num.len; i++) {
		int digit_index = buffer[i] - '0';

		Vector2 pos = {start_x + (i * GAP), position.y};

		num.digits[i] = new_digit(pos, digits[digit_index]);
	}

	return num;
}

void update_number(Number *num, unsigned short value, Vector2 position) {
	char buffer[7];

	snprintf(buffer, sizeof(buffer), "%0*d", num->len, value);

	num->position = position;

	float width = (num->len - 1) * GAP;
	float start_x = position.x - (width / 2.0f);

	for (int i = 0; i < num->len; i++) {
		int digit = buffer[i] - '0';

		Vector2 new_pos = {start_x + (i * GAP), position.y};

		num->digits[i] = new_digit(new_pos, digits[digit]);
	}
}

void draw_number(Number *num) {
	for (int i = 0; i < num->len; i++) {
		draw_digit(&num->digits[i]);
	}
}

void free_number(Number *num) { free(num->digits); }
