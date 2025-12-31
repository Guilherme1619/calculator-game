#include "raylib.h"
int main()
{
    //window dimensions
    int width{1050};
    int height{600};
    InitWindow(width, height, "Guizado window");

    SetTargetFPS(60);
    while (WindowShouldClose()==false)
    {
        BeginDrawing();
        ClearBackground(DarkBlue);

        //Game Logic Begins
        DrawCircle(circle_x,circle_y,50,RED);

        if (IsKeyDown(KEY_D))
        {
            circle_x = circle_x + 10;
        }

        if (IsKeyDown(KEY_A))
        {
            circle_x = circle_x - 10;
        }

        if (IsKeyDown(KEY_S))
        {
            circle_y = circle_y + 10;
        }

        if (IsKeyDown(KEY_W))
        {
            circle_y = circle_y - 10;
        }

        //Game Logic Ends
        EndDrawing();
    }
    CloseWindow();
    return 0;
}