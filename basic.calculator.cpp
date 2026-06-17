#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char operation;

    cout << "=== BASIC ARITHMETIC CALCULATOR ===" << endl;
    cout << "-----------------------------------" << endl;

    // Input first number
    cout << "Enter the first number: ";
    cin >> num1;

    // Input operator
    cout << "Enter an operator (+, -, *, /): ";
    cin >> operation;

    // Input second number
    cout << "Enter the second number: ";
    cin >> num2;

    cout << "-----------------------------------" << endl;

    // Arithmetic logic based on user input
    if (operation == '+') {
        result = num1 + num2;
        cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
    } 
    else if (operation == '-') {
        result = num1 - num2;
        cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
    } 
    else if (operation == '*') {
        result = num1 * num2;
        cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
    } 
    else if (operation == '/') {
        // Handling division by zero error
        if (num2 == 0) {
            cout << "Error! Division by zero is not allowed." << endl;
        } else {
            result = num1 / num2;
            cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
        }
    } 
    else {
        cout << "Invalid operator! Please use +, -, *, or /." << endl;
    }

    cout << "-----------------------------------" << endl;
    cout << "Program finished successfully." << endl;

    return 0;
}
