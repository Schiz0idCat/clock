#include "clock.h"

const int WIDTH = 1200;
const int HEIGHT = 400;

int main() {
	const time_t curr_time = time(NULL);
	char *time_str = ctime(&curr_time);

	InitWindow(WIDTH, HEIGHT, TITLE);

	Number number = new_number(4367, CENTER);

	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_Q)) {
			break;
		}

		BeginDrawing();
		ClearBackground(BLACK);

		draw_number(&number);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
