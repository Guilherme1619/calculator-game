#include <iostream>
#include <iomanip>
#include <string>
#include <raylib.h>
#include <sstream>
using namespace std;

// Calculator

int s = 8;

string calculate(double a, double b, char op, int s) {
    if(op == '+') {
        ostringstream out;
        out << setprecision(s) << (a + b);
        return out.str();
    }
    if(op == '-') {
        ostringstream out;
        out << setprecision(s) << (a - b);
        return out.str();
    }
    if(op == '*') {    
        ostringstream out;
        out << setprecision(s) << (a * b);
        return out.str();
    }
    if(op == '/' && b != 0){
        ostringstream out;
        out << setprecision(s) << (a / b);
        return out.str();
    }
return "Error";
}

// Main

int main() {

    string inputA = "";
    string inputB = "";
    string inputOp = "";
    string inputS = "8";

    int width{1000}; //x
    int height{600}; //y
    
    int rectangle_x = 60;
    int rectangle_y = 150;

    double a = 0;
    double b = 0;
    char op = ' ';
    int s = 8;

    bool aEntered = false;
    bool bEntered = false;
    bool opEntered = false;
    bool sEntered = false;

// Window

    InitWindow(width, height, "Calculator");
    SetTargetFPS(60);

    while (WindowShouldClose()==false) {

// Input

        int key = GetCharPressed();
        if (key >= 32 && key <= 126 && key != 102 && key != 114) {
            if (opEntered == false) {
                op = (char)key;
            }
            else if (aEntered == false) {
                inputA += (char)key;
            }
            else if (bEntered == false) {
                inputB += (char)key;
            }
            else if (sEntered == false) {
                inputS += (char)key;
            }
        }

// Enter

        if (IsKeyPressed(KEY_ENTER)) {
            if (opEntered == false && op != ' ') {
                opEntered = true;
            }
            else if (aEntered == false && inputA != "") {
                a = stod(inputA);
                aEntered = true;
            }
            else if (bEntered == false && inputB != "") {
                b = stod(inputB);
                bEntered = true;
            }
            else if (sEntered == false && inputS != "") {
                s = stod(inputS);
                sEntered = true;
            }
        }

// Delete

        if (IsKeyPressed(KEY_BACKSPACE)) {
            if (opEntered == false) {
                op = 0;
            }
            else if (aEntered == false && inputA.length() > 0) {
                inputA.pop_back();
            }
            else if (bEntered == false && inputB.length() > 0) {
                inputB.pop_back();
            }
            else if (sEntered == false && inputS.length() > 0) {
                inputS.pop_back();
            }
        }

// Reset

        if (IsKeyPressed(KEY_R)) {
            aEntered = false;
            bEntered = false;
            opEntered = false;
            sEntered = false;
            inputA = "";
            inputB = "";
            inputOp = "";
            inputS = "";
            op = ' ';
            a = 0;
            b = 0;
            s = 8;
        }

// Fullscreen
    if (IsKeyPressed(KEY_F)) {
        ToggleFullscreen();
    }
        
// Draw

        BeginDrawing();
        ClearBackground(BLACK);

        DrawRectangle(rectangle_x, rectangle_y, 880, 300, LIGHTGRAY);

        DrawText("Operator:", rectangle_x + 20, rectangle_y + 20, 20, BLACK);
        DrawText(TextFormat("%c", op == ' ' ? '_' : op), rectangle_x + 150, rectangle_y + 20, 20, BLACK);

        DrawText(("A: " + inputA).c_str(), rectangle_x + 20, rectangle_y + 70, 20, BLACK);

        DrawText(("B: " + inputB).c_str(), rectangle_x + 20, rectangle_y + 110, 20, BLACK);

        DrawText(("Significant Figures: " + inputS).c_str(), rectangle_x + 20, rectangle_y + 150, 20, BLACK);

        DrawText("[R] to Reset", rectangle_x + 20, rectangle_y + 250, 20, RED);

        DrawText("[F] for Fullscreen ] [", 720, 20, 25, RED);

// User Guide

        if (opEntered == false) {
            DrawText("Enter operator (+, -, *, /) and press Enter", rectangle_x + 20, rectangle_y + 220, 20, RED);
        }
        else if (opEntered == true && op != '+' && op != '-' && op != '*' && op != '/') {
            DrawText("Error: Invalid Operator", 20, 50, 70, RED);
        }
        else if (aEntered == false) {
            DrawText("Enter value for A and press Enter", rectangle_x + 20, rectangle_y + 220, 20, RED);
        }
        else if (bEntered == false) {
            DrawText("Enter value for B and press Enter", rectangle_x + 20, rectangle_y + 220, 20, RED);
        }
        else if (sEntered == false) {
            DrawText("Enter significant figures and press Enter", rectangle_x + 20, rectangle_y + 220, 20, RED);
        }

// Display Result

        if (aEntered == true && bEntered == true && opEntered == true && ((op == '/' && b != 0) || op != '/') && sEntered == true) {
            string result = calculate(a, b, op, s);
            DrawText(("Result: " + result).c_str(), 20, 50, 70, WHITE);
        }
        else if (opEntered == true && op == '/' && bEntered == true && b == 0) {
            DrawText("Error: Division by zero", 20, 50, 70, RED);
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
//make main && ./main
//./main