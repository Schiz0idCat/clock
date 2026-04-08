#include "clock.h"

int main() {
	// these two variables should be a function that gets the resolution
	// dynamically, but I don't know how to do it with hyprland.
	int native_width = 1920;
	int native_height = 1080;

	int window_width = native_width * 0.6f;
	int window_height = native_height * 0.3f;

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	SetTargetFPS(30);
	InitWindow(window_width, window_height, TITLE);

	Time t = new_time();

	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_Q)) {
			break;
		}

		BeginDrawing();
		ClearBackground(BLACK);

		update_time(&t);
		draw_time(&t);

		EndDrawing();
	}

	CloseWindow();

	free_time(&t);

	return 0;
}
