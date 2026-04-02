#ifndef WINDOW_H
#define WINDOW_H

#include <raylib.h>

#define TITLE "Digital Clock"

#define CENTER_X GetScreenWidth() / 2.0f
#define CENTER_Y GetScreenHeight() / 2.0f
#define CENTER                                                                 \
	(Vector2) { CENTER_X, CENTER_Y }

#endif
