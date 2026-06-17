#include <iostream>
using namespace std;

int main() {
    double score;

    cout << "=== STUDENT GRADING SYSTEM ===" << endl;
    cout << "------------------------------" << endl;

    // Input student score
    cout << "Enter the student's score (0-100): ";
    cin >> score;

    cout << "------------------------------" << endl;

    // Logic validation and grading scale
    if (score < 0 || score > 100) {
        cout << "Error! Invalid score. Please enter a value between 0 and 100." << endl;
    } 
    else if (score >= 85) {
        cout << "Grade: A" << endl;
        cout << "Status: Outstanding Performance!" << endl;
    } 
    else if (score >= 70) {
        cout << "Grade: B" << endl;
        cout << "Status: Good Job!" << endl;
    } 
    else if (score >= 55) {
        cout << "Grade: C" << endl;
        cout << "Status: Satisfactory. Keep improving!" << endl;
    } 
    else if (score >= 40) {
        cout << "Grade: D" << endl;
        cout << "Status: Pass with conditions." << endl;
    } 
    else {
        cout << "Grade: F" << endl;
        cout << "Status: Fail. Needs significant improvement." << endl;
    }

    cout << "------------------------------" << endl;
    cout << "Program finished successfully." << endl;

    return 0;
}
