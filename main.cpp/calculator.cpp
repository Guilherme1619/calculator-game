#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char n;
    cout << "Select function: + - * /: ";
    cin >> n;

    if (n != '+' && n != '-' && n != '*' && n != '/') {
        cout << "Error, invalid function" << endl;
        return 1;
    } 
    
    double a, b, c = 0;
    cout << "First number: ";
    cin >> a;
    cout << "Second number: ";
    cin >> b;

    if (n == '+') {
        c = a + b;
        cout << a << " + " << b << " = " << c << endl;
    } else if (n == '-') {
        c = a - b;
        cout << a << " - " << b << " = " << c << endl;
    } else if (n == '*') {
        c = a * b;
        cout << a << " * " << b << " = " << c << endl;
    } else if (n == '/') {
        if (b != 0) {
            c = a / b;
            cout << a << " / " << b << " = " << c << endl;
        } else {
            cout << "Can't divide by zero" << endl;
            return 1;
        }
    }

    char r;
    cout << "Round to 3 s.f.? (y/n): ";
    cin >> r;
    if (r == 'y') {
        cout << setprecision(3);
        cout << "Final value = " << c << endl;
    } else if (r == 'n') {
        cout << "Final value = " << c << endl;
    } else {
        cout << "Invalid answer" << endl;
    }

    return 0;
}