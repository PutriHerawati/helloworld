#include <iostream>
#include <string>

using namespace std;

int main() {
    int lightIntensity;
    int displayBrightness;
    string screenMode;

    cout << "=== SAMSUNG GALAXY DISPLAY OPTIMIZER INITIATED ===\n\n";
    cout << "Enter ambient light level in Lux (0 to 1000):\n";
    cout << "(0 = Pitch Black, 500 = Normal Room, 1000 = Direct Sunlight)\n";
    cout << "Light Input: ";
    cin >> lightIntensity;

    // Simple automation logic using standard if-else controls
    if (lightIntensity <= 100) {
        displayBrightness = 15; // Low brightness to protect eyes in the dark
        screenMode = "Eye Comfort Shield Mode Activated";
    } 
    else if (lightIntensity > 100 && lightIntensity <= 700) {
        displayBrightness = 50; // Standard medium brightness for indoor usage
        screenMode = "Standard Indoor Mode Activated";
    } 
    else {
        displayBrightness = 100; // Maximum brightness for high outdoor visibility
        screenMode = "Vision Booster Outdoor Mode Activated";
    }

    // Printing out the official Samsung simulation report
    cout << "\n=======================================================\n";
    cout << "         SAMSUNG ONE UI DISPLAY REPORT                 \n";
    cout << "=======================================================\n";
    cout << "Ambient Light Detected : " << lightIntensity << " Lux\n";
    cout << "Screen Brightness Level: " << displayBrightness << "%\n";
    cout << "Current Device State   : " << screenMode << "\n";
    cout << "=======================================================\n";

    return 0;
}
