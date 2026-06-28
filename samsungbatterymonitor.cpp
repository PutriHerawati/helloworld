#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Class representing an individual running application on the Galaxy device
class AppProcess {
private:
    string appName;
    double batteryDrainRate; // Battery drain per simulation tick (%)
    bool isThrottled;        // Reduced performance flag under Power Saving Mode

public:
    AppProcess(string name, double drainRate) {
        appName = name;
        batteryDrainRate = drainRate;
        isThrottled = false;
    }

    string getAppName() const { return appName; }
    
    double getBatteryDrainRate() const { 
        return isThrottled ? (batteryDrainRate * 0.4) : batteryDrainRate; 
    }
    
    bool getIsThrottled() const { return isThrottled; }

    // Toggle Samsung background restriction / throttling
    void setThrottling(bool status) {
        isThrottled = status;
    }
};

// Class representing the Samsung Galaxy Device Battery Optimizer Engine
class SamsungBatteryOptimizer {
private:
    double batteryLevel;
    bool isPowerSavingMode;
    vector<AppProcess> activeApps;

public:
    SamsungBatteryOptimizer() {
        batteryLevel = 100.0;
        isPowerSavingMode = false;
    }

    void launchApp(string name, double baseDrainRate) {
        activeApps.push_back(AppProcess(name, baseDrainRate));
        cout << "[One UI Engine] Launched: " << name << " (Base Drain: " << baseDrainRate << "%/tick)\n";
    }

    // Trigger Samsung's signature power-saving algorithms
    void activatePowerSavingMode() {
        isPowerSavingMode = true;
        cout << "\n⚠️ [One UI Notification] Battery critical! Activating Power Saving Mode...\n";
        cout << "💡 [Optimization] Restricting CPU performance and throttling background apps by 60%.\n";
        
        for (auto& app : activeApps) {
            app.setThrottling(true);
        }
    }

    // Simulate one cycle of device usage (1 tick)
    void runSimulationTick() {
        if (activeApps.empty()) {
            cout << "\nℹ️ No active apps running. Device is on standby.\n";
            return;
        }

        double totalDrainThisTick = 0.0;
        
        cout << "\n=======================================================\n";
        cout << "         SAMSUNG GALAXY PERFORMANCE MONITOR            \n";
        cout << "=======================================================\n";
        cout << left << setw(18) << "APP NAME" << setw(15) << "DRAIN RATE" << setw(15) << "CPU LIMIT" << "\n";
        cout << "-------------------------------------------------------\n";

        for (const auto& app : activeApps) {
            double currentDrain = app.getBatteryDrainRate();
            totalDrainThisTick += currentDrain;

            string restrictionStatus = app.getIsThrottled() ? "⚠️ 60% Throttled" : "✅ Unrestricted";
            cout << left << setw(18) << app.getAppName() 
                 << "-" << fixed << setprecision(1) << currentDrain << "%/tick      " 
                 << setw(15) << restrictionStatus << "\n";
        }

        // Deduct battery
        batteryLevel -= totalDrainThisTick;
        if (batteryLevel < 0.0) batteryLevel = 0.0;

        cout << "-------------------------------------------------------\n";
        cout << "🔋 CURRENT BATTERY LEVEL : " << fixed << setprecision(1) << batteryLevel << "%\n";
        cout << "⚙️ POWER SAVING STATUS    : " << (isPowerSavingMode ? "ACTIVE" : "OFF") << "\n";
        cout << "=======================================================\n";

        // Intelligent automation check
        if (batteryLevel <= 20.0 && !isPowerSavingMode) {
            activatePowerSavingMode();
        }
    }

    double getBatteryLevel() const { return batteryLevel; }
};

int main() {
    cout << "=== MILESTONE 12: SAMSUNG GALAXY BATTERY OPTIMIZER INITIALIZED ===\n\n";

    SamsungBatteryOptimizer galaxyS26;

    // Simulate standard daily app usage on a flagship device
    galaxyS26.launchApp("Genshin_Impact", 8.5);
    galaxyS26.launchApp("Samsung_Camera_4K", 6.0);
    galaxyS26.launchApp("TikTok_Background", 3.0);
    galaxyS26.launchApp("WhatsApp_Service", 1.5);

    int cycle = 1;
    // Loop simulator execution until the device runs out of battery power
    while (galaxyS26.getBatteryLevel() > 0.0) {
        cout << "\n[TIME CYCLE: #" << cycle << "]";
        galaxyS26.runSimulationTick();
        cycle++;
        
        // Safety exit for console presentation
        if (galaxyS26.getBatteryLevel() == 0.0) {
            cout << "\n💀 [System] Galaxy device battery depleted. Shutting down hardware processes.\n";
            break;
        }
    }

    return 0;
}
