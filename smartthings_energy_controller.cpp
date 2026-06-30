#include <iostream>
#include <string>

using namespace std;

int main() {
   
    int totalHomeLoad;     
    int powerLimitPercent; 
    string smartThingsMode;  

    cout << "=== SAMSUNG SMARTTHINGS ENERGY CONTROLLER INITIATED ===\n\n";

    cout << "Enter current total home electricity load in Watts:\n";
    cout << "(e.g., 900W for low use, 2200W for medium, 4400W for heavy overload)\n";
    cout << "Current Load Input (Watts): ";
    cin >> totalHomeLoad;

    if (totalHomeLoad <= 1300) {
       
        smartThingsMode = "Normal Operation Mode";
        powerLimitPercent = 100;
    } 
    else if (totalHomeLoad > 1300 && totalHomeLoad <= 3500) {
    
        smartThingsMode = "SmartThings AI Energy Mode";
        powerLimitPercent = 70;
    } 
    else {
        
        smartThingsMode = "Emergency Power Saver Activated";
        powerLimitPercent = 40;
    }

    cout << "\n==================================================\n";
    cout << "SAMSUNG SMARTTHINGS HOME ENERGY MONITOR:\n";
    cout << "--------------------------------------------------\n";
    cout << "Total Home Power Load : " << totalHomeLoad << " Watts\n";
    cout << "Active Ecosystem Mode : " << smartThingsMode << "\n";
    cout << "Device Power Limit    : " << powerLimitPercent << "%\n";
    cout << "==================================================\n";
    cout << "=== SYSTEM RUNNING STABLY - DATA SYNCED TO CLOUD ===\n";

    return 0;
}
