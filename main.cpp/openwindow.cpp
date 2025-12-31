#include <iostream>
#include <iomanip>
#include <string>
#include <raylib.h>
using namespace std;

int main()
{
    int width{1200};
    int height{700};
    InitWindow(width, height, "Calculator Game");

    int rectangle_x{200};
    int rectangle_y{200};

    SetTargetFPS(60);
    while (WindowShouldClose()==false)
    {
        BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawRectangle(rectangle_x,rectangle_y,800,300,LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
}