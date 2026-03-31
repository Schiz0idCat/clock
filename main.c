#include "clock.h"

const int WIDTH = 1200;
const int HEIGHT = 400;

int main() {
  const time_t curr_time = time(NULL);
  char *time_str = ctime(&curr_time);

  InitWindow(WIDTH, HEIGHT, TITLE);

  Segment segment = new_segment(CENTER, deg2rad(90));

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_Q)) {
      break;
    }

    BeginDrawing();
    ClearBackground(BLACK);

    draw_segment(&segment);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
