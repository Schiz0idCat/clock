#include "time.h"
#include "../tools/window/window.h"
#include <time.h>

#define SECTION_GAP (SEG_LENGTH * 8.0f)
#define DOT_GAP (SECTION_GAP / 2.0f)
#define HOUR_POS                                                               \
	(Vector2) { CENTER_X - SECTION_GAP, CENTER_Y }
#define MIN_POS                                                                \
	(Vector2) { CENTER_X, CENTER_Y }
#define SEC_POS                                                                \
	(Vector2) { CENTER_X + SECTION_GAP, CENTER_Y }

Time new_time() {
	Time ct;

	ct.position = CENTER;

	ct.hour = new_number(11, HOUR_POS);
	ct.minutes = new_number(11, MIN_POS);
	ct.seconds = new_number(11, SEC_POS);

	update_time(&ct);

	return ct;
}

void update_time(Time *ct) {
	const time_t now = time(NULL);
	struct tm *t = localtime(&now);

	ct->position = CENTER;

	update_number(&ct->hour, (unsigned short)t->tm_hour, HOUR_POS);
	update_number(&ct->minutes, (unsigned short)t->tm_min, MIN_POS);
	update_number(&ct->seconds, (unsigned short)t->tm_sec, SEC_POS);
}

void draw_separator(Vector2 pos) {
	float radius = SEG_THICKNESS * 2.4f;
	float offset = SEG_LENGTH * 1.0f;

	DrawCircle(pos.x, pos.y - offset, radius, ON);
	DrawCircle(pos.x, pos.y + offset, radius, ON);
}

void draw_time(Time *ct) {
	draw_number(&ct->hour);
	draw_number(&ct->minutes);
	draw_number(&ct->seconds);

	float gap = DOT_GAP;

	draw_separator((Vector2){ct->position.x + gap, ct->position.y});
	draw_separator((Vector2){ct->position.x - gap, ct->position.y});
}

void free_time(Time *ct) {
	free_number(&ct->hour);
	free_number(&ct->minutes);
	free_number(&ct->seconds);
}
