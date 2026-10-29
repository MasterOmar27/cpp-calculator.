#include <iostream>
#include <limits>
using namespace std;
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b == 0) return numeric_limits<double>::quiet_NaN();
    return a / b;
}
// Operation: 1 = +, 2 = -, 3 = *, 4 = /
extern "C" double calculate(double a, double b, int operation) {
    if (operation == 1) return add(a, b);
    if (operation == 2) return subtract(a, b);
    if (operation == 3) return multiply(a, b);
    if (operation == 4) return divide(a, b);
    return numeric_limits<double>::quiet_NaN();
}
#ifndef __EMSCRIPTEN__
int main() {
    double a, b;
    int operation;

    cout << "First number: ";
    cin >> a;
    cout << "Second number: ";
    cin >> b;
    cout << "Operation (1=+, 2=-, 3=*, 4=/): ";
    cin >> operation;
    cout << "Result: " << calculate(a, b, operation) << endl;
    return 0;
}
#endif