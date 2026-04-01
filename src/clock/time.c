#include "time.h"
#include <time.h>

Time new_time(Vector2 position) {
	Time ct;
	float gap = 500.0f; // gap between HH, MM and SS

	ct.hour = new_number(11, (Vector2){position.x - gap, position.y});
	ct.minutes = new_number(11, (Vector2){position.x, position.y});
	ct.seconds = new_number(11, (Vector2){position.x + gap, position.y});

	update_time(&ct);

	return ct;
}

void update_time(Time *ct) {
	const time_t now = time(NULL);
	struct tm *t = localtime(&now);

	update_number(&ct->hour, (unsigned short)t->tm_hour);
	update_number(&ct->minutes, (unsigned short)t->tm_min);
	update_number(&ct->seconds, (unsigned short)t->tm_sec);
}

void draw_separator(Vector2 pos) {
	float radius = 30.0f;
	float offset = 60.0f;

	DrawCircle(pos.x, pos.y - offset, radius, ON);
	DrawCircle(pos.x, pos.y + offset, radius, ON);
}

void draw_time(Time *ct) {
	draw_number(&ct->hour);
	draw_number(&ct->minutes);
	draw_number(&ct->seconds);

	float gap = 500.0f;

	draw_separator((Vector2){ct->position.x + gap, ct->position.y + 200});
	draw_separator((Vector2){ct->position.x + gap + gap, ct->position.y + 200});
}

void free_time(Time *ct) {
	free_number(&ct->hour);
	free_number(&ct->minutes);
	free_number(&ct->seconds);
}
