#include "clock.h"

const int WIDTH = 1500;
const int HEIGHT = 400;

int main() {
	SetTargetFPS(30);
	InitWindow(WIDTH, HEIGHT, TITLE);

	Time t = new_time(CENTER);

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
