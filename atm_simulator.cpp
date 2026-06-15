#include <iostream>
using namespace std;

int main() {
    int choice;
    double balance = 500000; // Initial balance: Rp 500,000
    double deposit, withdraw;
    
    cout << "=== SMART ATM SIMULATOR ===" << endl;
    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Select an option (1-4): ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Your current balance is: Rp " << balance << endl;
                break;
            case 2:
                cout << "Enter deposit amount: Rp ";
                cin >> deposit;
                balance += deposit;
                cout << "Deposit successful! Your new balance is: Rp " << balance << endl;
                break;
            case 3:
                cout << "Enter withdrawal amount: Rp ";
                cin >> withdraw;
                if (withdraw > balance) {
                    cout << "Transaction Failed! Insufficient balance." << endl;
                } else {
                    balance -= withdraw;
                    cout << "Withdrawal successful! Remaining balance: Rp " << balance << endl;
                }
                break;
            case 4:
                cout << "Thank you for using Smart ATM Simulator! Goodbye." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while(choice != 4);
    
    return 0;
}
