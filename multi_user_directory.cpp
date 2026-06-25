#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Struktur data untuk menyimpan profil pengguna
struct UserProfile {
    string name;
    int birthYear;
    int age;
};

int main() {
    int currentYear = 2026; // Mengikuti basis data waktu saat ini
    int totalUsers;
    vector<UserProfile> directory;

    cout << "=== MULTI-USER DIRECTORY & AGE VERIFIER ===" << endl;
    cout << "Enter total users to register: ";
    cin >> totalUsers;
    cout << "------------------------------------------" << endl;

    // Loop Penginputan Data (Milestone 9 Core Feature)
    for (int i = 0; i < totalUsers; i++) {
        UserProfile user;
        cout << "\n[User #" << i + 1 << " Configuration]" << endl;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, user.name);

        cout << "Enter birth year (e.g., 2006): ";
        cin >> user.birthYear;

        // Validasi logika input 
        if (user.birthYear > currentYear || user.birthYear < 1900) {
            cout << "⚠️ Error: Invalid birth year configuration for " << user.name << "." << endl;
            i--; // Mengulang iterasi untuk user yang sama karena input salah
            continue;
        }

        // Kalkulasi umur dasar
        user.age = currentYear - user.birthYear;
        
        // Memasukkan data valid ke dalam array/vector directory
        directory.push_back(user);
    }

    // Output Ringkasan Data Terformat
    cout << "\n==========================================" << endl;
    cout << "         REGISTERED USERS SUMMARY         " << endl;
    cout << "==========================================" << endl;
    for (const auto& u : directory) {
        cout << "Name: " << u.name << " | Birth Year: " << u.birthYear 
             << " | Calculated Age: " << u.age << " years old." << endl;
    }
    cout << "------------------------------------------" << endl;

    return 0;
}
