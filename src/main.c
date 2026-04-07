#include "clock.h"

int main() {
	int window_width = 800;
	int window_height = 450;

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
