#include <raylib.h>
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
        ClearBackground(DARKBLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}