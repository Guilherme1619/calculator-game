#include <iostream>
#include <iomanip>
#include <string>
#include <raylib.h>
using namespace std;

string calculate(double a, double b, char n) {
    if(n == '+') return to_string(a + b);
    if(n == '-') return to_string(a - b);
    if(n == '*') return to_string(a * b);
    if(n == '/' && b != 0) return to_string(a / b);
    if(n == '/' && b == 0) return "Error: Division by zero";
    if(n != '+' && n != '-' && n != '*' && n != '/') {
        cout << "Error, invalid function" << endl;
    return 0;
    }
}

int main() {
    int width{1200};
    int height{700};
    
    InitWindow(width, height, "Calculator Game");
    SetTargetFPS(60);
    
    int rectangle_x = 200;
    int rectangle_y = 200;

    char n;
    double a, b;

    while (WindowShouldClose()==false) {
        BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawRectangle(rectangle_x,rectangle_y,800,300,LIGHTGRAY);

        while (n == 0) {
        DrawText("Enter operation (+, -, *, /): ", rectangle_x, rectangle_y, 20, BLACK);
        cin >> n;
        }

        while (a == 0) {
        DrawText("Enter first number: ", rectangle_x + 20, rectangle_y + 60, 20, BLACK);
        cin >> a;
        }

        while (b == 0) {
        DrawText("Enter second number: ", rectangle_x + 20, rectangle_y + 100, 20, BLACK);
        cin >> b;
        }

        string c = calculate(a, b, n);
        DrawText(c.c_str(), rectangle_x + 20, rectangle_y + 140, 20, BLACK);

        EndDrawing();
    }
    CloseWindow();
}