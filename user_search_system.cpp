#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Untuk manipulasi teks dasar

using namespace std;

// Struktur data profil pengguna
struct UserProfile {
    string name;
    int birthYear;
    int age;
};

int main() {
    int currentYear = 2026; 
    int totalUsers;
    vector<UserProfile> directory;

    cout << "=== MILESTONE 10: USER DIRECTORY & INTERACTIVE SEARCH ===" << endl;
    cout << "Enter total users to register: ";
    cin >> totalUsers;
    cout << "--------------------------------------------------------" << endl;

    // Loop Input Data Pengguna (Dari Milestone 9)
    for (int i = 0; i < totalUsers; i++) {
        UserProfile user;
        cout << "\n[Registering User #" << i + 1 << "]" << endl;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, user.name);

        cout << "Enter birth year: ";
        cin >> user.birthYear;

        if (user.birthYear > currentYear || user.birthYear < 1900) {
            cout << "⚠️ Error: Invalid birth year for " << user.name << ". Please re-enter." << endl;
            i--; 
            continue;
        }

        user.age = currentYear - user.birthYear;
        directory.push_back(user);
    }

    // --- FITUR BARU MILESTONE 10: SISTEM PENCARIAN INTERAKTIF ---
    cout << "\n========================================================" << endl;
    cout << "                INTERACTIVE SEARCH SYSTEM               " << endl;
    cout << "========================================================" << endl;
    
    string searchQuery;
    bool found = false;

    cout << "Enter the name you want to search for: ";
    cin.ignore();
    getline(cin, searchQuery);

    cout << "\nSearching in directory..." << endl;
    cout << "--------------------------------------------------------" << endl;

    // Loop Linear Search untuk mencocokkan data
    for (const auto& u : directory) {
        if (u.name == searchQuery) {
            cout << "✨ Match Found! ✨" << endl;
            cout << "Name           : " << u.name << endl;
            cout << "Birth Year     : " << u.birthYear << endl;
            cout << "Calculated Age : " << u.age << " years old" << endl;
            found = true;
            break; // Hentikan pencarian jika sudah ketemu
        }
    }

    if (!found) {
        cout << "❌ User '" << searchQuery << "' was not found in the directory." << endl;
    }
    cout << "--------------------------------------------------------" << endl;

    return 0;
}
