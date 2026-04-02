#include "clock.h"

int main() {
	int monitor = GetCurrentMonitor();

	int screen_width = GetMonitorWidth(monitor);
	int screen_height = GetMonitorHeight(monitor);

	int window_width = (int)(screen_width * 0.7f);
	int window_height = (int)(screen_height * 0.4f);

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	SetTargetFPS(30);
	InitWindow(window_width, window_height, TITLE);

	SetWindowPosition(screen_width / 2, screen_height / 2);

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
