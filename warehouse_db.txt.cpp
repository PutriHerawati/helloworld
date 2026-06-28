#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Class representing a product in the warehouse
class Product {
private:
    string id;
    string name;
    int stock;
    int minThreshold; // Trigger notification if stock drops below this number

public:
    // Constructor
    Product(string id, string name, int stock, int minThreshold) {
        this->id = id;
        this->name = name;
        this->stock = stock;
        this->minThreshold = minThreshold;
    }

    // Getters
    string getId() const { return id; }
    string getName() const { return name; }
    int getStock() const { return stock; }
    int getMinThreshold() const { return minThreshold; }

    // Setter to update stock level
    void setStock(int newStock) { this->stock = newStock; }

    // Check if the product requires a restock
    bool needsRestock() const {
        return stock <= minThreshold;
    }
};

// Class handling warehouse inventory management
class WarehouseManager {
private:
    vector<Product> productList;
    string databaseFilename;

    // Internal function to load data from the database file
    void loadDataFromFile() {
        ifstream file(databaseFilename);
        if (!file.is_open()) return; // Ignore if file does not exist yet

        string id, name;
        int stock, minThreshold;
        
        // Reading structured data line by line
        while (file >> id >> ws && getline(file, name, ',') && file >> stock >> minThreshold) {
            productList.push_back(Product(id, name, stock, minThreshold));
        }
        file.close();
    }

public:
    // Constructor automatically triggers database synchronization
    WarehouseManager(string filename) {
        databaseFilename = filename;
        loadDataFromFile();
    }

    // Save current memory state back to the database file (.txt)
    void saveDataToFile() {
        ofstream file(databaseFilename);
        for (const auto& p : productList) {
            // Storage Format: ID Name,Stock MinThreshold
            file << p.getId() << " " << p.getName() << "," << p.getStock() << " " << p.getMinThreshold() << "\n";
        }
        file.close();
    }

    // Add a brand new product to the inventory list
    void addProduct(string id, string name, int stock, int minThreshold) {
        // Validation check for unique ID
        for (const auto& p : productList) {
            if (p.getId() == id) {
                cout << "\n❌ Error! Product with ID " << id << " already exists in the system.\n";
                return;
            }
        }
        productList.push_back(Product(id, name, stock, minThreshold));
        saveDataToFile(); // Persistent auto-save
        cout << "\n✅ Product \"" << name << "\" successfully added to the warehouse inventory!\n";
    }

    // Update stock levels using a targeted product ID
    void updateStock(string id, int newStock) {
        for (auto& p : productList) {
            if (p.getId() == id) {
                p.setStock(newStock);
                saveDataToFile(); // Persistent auto-save
                cout << "\n✅ Stock level for Product ID " << id << " successfully updated to: " << newStock << "\n";
                return;
            }
        }
        cout << "\n❌ Error! Product with ID " << id << " could not be found.\n";
    }

    // Display current warehouse report with real-time status alerts
    void displayInventory() {
        if (productList.empty()) {
            cout << "\n📭 The warehouse inventory is currently empty.\n";
            return;
        }

        cout << "\n===============================================================\n";
        cout << "                   WAREHOUSE INVENTORY REPORT                  \n";
        cout << "===============================================================\n";
        cout << left << setw(12) << "PRODUCT ID" << setw(25) << "PRODUCT NAME" << setw(10) << "STOCK" << setw(15) << "STATUS" << "\n";
        cout << "---------------------------------------------------------------\n";
        
        for (const auto& p : productList) {
            string status = p.needsRestock() ? "⚠️ NEEDS RESTOCK" : "✅ SECURE";
            cout << left << setw(12) << p.getId() 
                 << setw(25) << p.getName() 
                 << setw(10) << p.getStock() 
                 << setw(15) << status << "\n";
        }
        cout << "===============================================================\n";
    }
};

// Main execution function / Terminal UI Interface
int main() {
    // Initializing the management engine linked with an external storage file
    WarehouseManager manager("database_gudang.txt");
    int choice;

    cout << "=== MILESTONE 11: SMART WAREHOUSE INVENTORY INITIATED ===\n";

    do {
        cout << "\n--- MAIN NAVIGATION MENU ---\n";
        cout << "1. Display Full Inventory Report\n";
        cout << "2. Register New Product Record\n";
        cout << "3. Update Existing Stock Level\n";
        cout << "4. Terminate and Exit System\n";
        cout << "Select an option (1-4): ";
        cin >> choice;

        if (choice == 1) {
            manager.displayInventory();
        } 
        else if (choice == 2) {
            string id, name;
            int stock, minThreshold;
            cout << "\nEnter Product ID (e.g., PROD01): ";
            cin >> id;
            cout << "Enter Product Name (use (_) for spaces, e.g., Liquid_Soap): ";
            cin >> name;
            cout << "Enter Initial Stock Quantity: ";
            cin >> stock;
            cout << "Enter Minimum Reorder Threshold (Alert Level): ";
            cin >> minThreshold;
            manager.addProduct(id, name, stock, minThreshold);
        } 
        else if (choice == 3) {
            string id;
            int newStock;
            cout << "\nEnter Target Product ID to update: ";
            cin >> id;
            cout << "Enter New Stock Quantity: ";
            cin >> newStock;
            manager.updateStock(id, newStock);
        }
        else if (choice == 4) {
            cout << "\n💾 System shutdown initiated. All data variations have been securely saved to database_gudang.txt.\n";
        } 
        else {
            cout << "\n❌ Invalid choice! Please select a valid option from the menu.\n";
        }
    } while (choice != 4);

    return 0;
}
