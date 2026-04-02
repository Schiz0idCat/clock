#ifndef TIME_H
#define TIME_H

#include "number.h"
#include <raylib.h>

typedef struct {
	Number hour;
	Number minutes;
	Number seconds;
	Vector2 position;
} Time;

Time new_time();
void update_time(Time *ct);
void draw_time(Time *ct);
void free_time(Time *ct);

#endif
