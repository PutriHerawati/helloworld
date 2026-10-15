#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

mutex logMutex;

struct SmartThingsDevice {
    string deviceId;
    string roomType;
    double currentTemperature;
    bool isEnergySaveEnabled;
};

class SmartThingsPlatformProcessor {
private:
    double energyThreshold;

public:
    SmartThingsPlatformProcessor(double threshold) : energyThreshold(threshold) {}

    void processDeviceTelemetry(SmartThingsDevice device) {

        this_thread::sleep_for(chrono::milliseconds(800));

        lock_guard<mutex> lock(logMutex);

        cout << "[INGESTION CENTRAL] Processing Device ID: " << device.deviceId
            << " | Room: " << device.roomType << endl;
        cout << " -> Telemetry Payload: Temperature = " << device.currentTemperature << "C" << endl;

        if (device.currentTemperature < energyThreshold) {
            device.isEnergySaveEnabled = true;
            cout << " -> [AUTOMATION ACTION]: High cooling efficiency detectd. 'ECO_MODE_ON' command." << endl;
        } else {
            device.isEnergySaveEnabled = false;
            cout << " -> [AUTOMATION ACTION]: Standard optimal permonve maintained." << endl;
        }
        cout << "------------------------------------------" << endl;
    }
};

int main() {
    cout << "=== SAMSUNG SMARTTHINGS CLOUD PLATFORM CORE (SEOCHO CENTRAL) ===" << endl;
    cout << "Initializing Multi-Thread Messaage Broker Ingestion..." << endl;
    cout << "=================================================" << endl;

    SmartThingsPlatformProcessor cloudEngine(20.0);

    vector<SmartThingsDevice> incomingStreams = {
        {"sam-ac-livingroom-01", "Living Room", 18.5, false},
        {"sam-ac-bedroom-02", "Master Bedroom", 22.3, false},
        {"sam-ac-serverroom-03", "Home Office/Server", 16.0, false},
        {"sam-ac-kitchen-04", "Kitchen Area", 24.5, false}
    };

    vector<thread> workerThreads;

    for (const auto& device : incomingStreams) {
        workerThreads.push_back(thread(&SmartThingsPlatformProcessor::processDeviceTelemetry, &cloudEngine, device));
    }

    for (auto& t : workerThreads) {
        if (t.joinable()) {
            t.join();
        }
    }

    cout << "System Sync Complete. All concurrent telemetries successfully parsed." << endl;
    return 0;
}
