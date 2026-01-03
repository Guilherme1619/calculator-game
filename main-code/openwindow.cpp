#include <iostream>
#include <iomanip>
#include <string>
#include <raylib.h>
using namespace std;

// Function to perform calculation based on operator

string calculate(double a, double b, char n) {
    if(n == '+') return to_string(a + b);
    if(n == '-') return to_string(a - b);
    if(n == '*') return to_string(a * b);
    if(n == '/' && b != 0) return to_string(a / b);
    if(n == '/' && b == 0) return "Error: Division by zero";
    if(n != '+' && n != '-' && n != '*' && n != '/') {
        cout << "Error, invalid function" << endl;
    return "error";
    }
}

// Main function to create window and handle user input

int main() {

    string inputA = "";
    string inputB = "";
    string inputN = "";

    int width{1200};
    int height{700};
    
    int rectangle_x = 200;
    int rectangle_y = 200;

    char n = 'w';
    double a = 0;
    double b = 0;

    bool aEntered = false;
    bool bEntered = false;

    InitWindow(width, height, "Calculator Game");
    SetTargetFPS(60);

    while (WindowShouldClose()==false) {

// Handle user input

        int key = GetCharPressed();
        if (key >= 32 && key <= 126) {
            if (n == 'w') {
                n = (char)key;
            }
            else if (aEntered == false) {
                inputA += (char)key;
            }
            else if (bEntered == false) {
                inputB += (char)key;
            }
        }

        if (IsKeyPressed(KEY_ENTER)) {
            if (aEntered == false && inputA != "") {
                a = stod(inputA);
                aEntered = true;
            }
            else if (bEntered == false && inputB != "") {
                b = stod(inputB);
                bEntered = true;
            }
        }

// Draw the window and display prompts/results

        BeginDrawing();
        ClearBackground(DARKBLUE);

        DrawRectangle(rectangle_x, rectangle_y, 800, 300, LIGHTGRAY);

        DrawText("Operator:", rectangle_x + 20, rectangle_y + 20, 20, BLACK);
        DrawText(TextFormat("%c", n == 0 ? '_' : n), rectangle_x + 150, rectangle_y + 20, 20, BLACK);

        DrawText(("A: " + inputA).c_str(), rectangle_x + 20, rectangle_y + 70, 20, BLACK);

        DrawText(("B: " + inputB).c_str(), rectangle_x + 20, rectangle_y + 110, 20, BLACK);

        if (aEntered == true && bEntered == true && n != 0) {
            string result = calculate(a, b, n);
            DrawText(("Result: " + result).c_str(), rectangle_x + 20, rectangle_y + 160, 20, BLACK);
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}