#include <iostream>
#include <limits>

using namespace std;

double add(double a, double b) { 
    return a + b; 
}

double subtract(double a, double b) { 
    return a - b; 
}

double multiply(double a, double b) { 
    return a * b; 
}

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
    if (!(cin >> a)) {
        cerr << "Invalid input for first number." << endl;
        return 1;
    }

    cout << "Second number: ";
    if (!(cin >> b)) {
        cerr << "Invalid input for second number." << endl;
        return 1;
    }

    cout << "Operation (1=+, 2=-, 3=*, 4=/): ";
    if (!(cin >> operation)) {
        cerr << "Invalid input for operation." << endl;
        return 1;
    }

    double result = calculate(a, b, operation);

    if (isnan(result)) {
        cout << "Result: Undefined / Division by zero" << endl;
    } else {
        cout << "Result: " << result << endl;
    }

    return 0;
}
#endif
