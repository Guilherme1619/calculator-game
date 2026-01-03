#include <iostream>
#include <iomanip>
#include <string>
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
    char n;
    double a, b;

    cout << "Enter operation (+, -, *, /): ";
    cin >> n;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    string c = calculate(a, b, n);
    cout << c << setprecision(3) << endl;

    return 0;
}