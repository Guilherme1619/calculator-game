#include <iostream>
#include <iomanip>
#include <string>
#include <raylib.h>
#include <sstream>
using namespace std;

// Function to perform calculation based on operator

string calculate(double a, double b, char n) {
    if(n == '+') {
        ostringstream out;
        out << fixed << setprecision(3) << (a + b);
        return out.str();
    }
    if(n == '-') {
        ostringstream out;
        out << fixed << setprecision(3) << (a - b);
        return out.str();
    }
    if(n == '*') {    
        ostringstream out;
        out << fixed << setprecision(3) << (a * b);
        return out.str();
    }
    if(n == '/' && b != 0){
        ostringstream out;
        out << fixed << setprecision(3) << (a / b);
        return out.str();
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

    char n = 0;
    double a = 0;
    double b = 0;

    bool aEntered = false;
    bool bEntered = false;
    bool nEntered = false;

    InitWindow(width, height, "Calculator Game");
    SetTargetFPS(60);

    while (WindowShouldClose()==false) {

// Handle user input

        int key = GetCharPressed();
        if (key >= 32 && key <= 126) {
            if (nEntered == false) {
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
            if (nEntered == false && (n == '+' || n == '-' || n == '*' || n == '/')) {
                nEntered = true;
            }
            else if (aEntered == false && inputA != "") {
                a = stod(inputA);
                aEntered = true;
            }
            else if (bEntered == false && inputB != "") {
                b = stod(inputB);
                bEntered = true;
            }
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            if (nEntered == false) {
                n = 0;
            }
            else if (aEntered == false && inputA.length() > 0) {
                inputA.pop_back();
            }
            else if (bEntered == false && inputB.length() > 0) {
                inputB.pop_back();
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

        if (nEntered == false) {
            DrawText("Enter operator (+, -, *, /) and press Enter", rectangle_x + 20, rectangle_y + 220, 20, RED);
        }
        else if (aEntered == false) {
            DrawText("Enter value for A and press Enter", rectangle_x + 20, rectangle_y + 220, 20, RED);
        }
        else if (bEntered == false) {
            DrawText("Enter value for B and press Enter", rectangle_x + 20, rectangle_y + 220, 20, RED);
        }

        if (aEntered == true && bEntered == true && nEntered == true) {
            string result = calculate(a, b, n);
            DrawText(("Result: " + result).c_str(), 20, 50, 70, WHITE);
        }

        if (n == "/" && b == 0) {
            DrawText("Error: Division by zero", 20, 50, 70, RED);
        }

        if (nEntered == true && n != '+' && n != '-' && n != '*' && n != '/') {
            DrawText("Error: Invalid Operator", 20, 50, 70, RED);
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
//make openwindow && ./openwindow