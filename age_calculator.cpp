#include <iostream>
using namespace std;

int main() {
    int birthYear, currentYear, age;

    cout << "=== AGE CALCULATOR & VERIFIER ===" << endl;
    cout << "---------------------------------" << endl;

    // Input configuration
    cout << "Enter your birth year (e.g., 2005): ";
    cin >> birthYear;

    cout << "Enter the current year (e.g., 2026): ";
    cin >> currentYear;

    cout << "---------------------------------" << endl;

    // Validation check for logical input errors
    if (birthYear > currentYear || birthYear < 1900) {
        cout << "Error! Invalid birth year configuration." << endl;
    } 
    else {
        // Core subtraction math
        age = currentYear - birthYear;
        cout << "Your calculated age is: " << age << " years old." << endl;
        cout << "---------------------------------" << endl;

        // Life stage categorization logic
        if (age >= 18) {
            cout << "Category: Adult" << endl;
            cout << "Status: Eligible for professional opportunities." << endl;
        } 
        else if (age >= 12) {
            cout << "Category: Teenager" << endl;
            cout << "Status: Focus on secondary technical education." << endl;
        } 
        else {
            cout << "Category: Child" << endl;
            cout << "Status: Early stage development." << endl;
        }
    }

    cout << "---------------------------------" << endl;
    cout << "Program finished successfully." << endl;

    return 0;
}
