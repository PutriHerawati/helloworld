#include <iostream>
#include <string>

using namespace std;

int main() {
    string message;
    int choice;
    int key = 3; // Shift key for encryption logic

    cout << "=== SECURE TEXT ENCRYPTER ===" << endl;
    cout << "1. Encrypt Message (Amankan Pesan)\n";
    cout << "2. Decrypt Message (Buka Pesan)\n";
    cout << "Select option (1-2): ";
    cin >> choice;
    cin.ignore(); // Clear the input buffer

    cout << "Enter the text message: ";
    getline(cin, message);

    if (choice == 1) {
        // Encryption logic
        for (int i = 0; i < message.length(); i++) {
            if (isalpha(message[i])) {
                message[i] = message[i] + key;
            }
        }
        cout << "Encrypted Result: " << message << endl;
    } 
    else if (choice == 2) {
        // Decryption logic
        for (int i = 0; i < message.length(); i++) {
            if (isalpha(message[i])) {
                message[i] = message[i] - key;
            }
        }
        cout << "Decrypted Result: " << message << endl;
    } 
    else {
        cout << "Invalid option!" << endl;
    }

    cout << "---------------------------------" << endl;
    cout << "Program finished successfully." << endl;
    return 0;
}
