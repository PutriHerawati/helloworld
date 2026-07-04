#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SmartNode {
public:
    string name;                   
    string type;                    
    vector<SmartNode*> children;    

    SmartNode(string nodeName, string nodeType) {
        name = nodeName;
        type = nodeType;
    }
};

void addComponent(SmartNode* parent, SmartNode* child) {
    parent->children.push_back(child);
}

void printSmartThingsTree(SmartNode* node, int depth = 0) {
    if (node == nullptr) return;

    for (int i = 0; i < depth; i++) {
        cout << "   |";
    }
    
    if (depth > 0) cout << "--> ";
    cout << node->name << " [" << node->type << "]\n";

    for (auto child : node->children) {
        printSmartThingsTree(child, depth + 1);
    }
}

int main() {
    cout << "=== SAMSUNG SMARTTHINGS IOT HUB TOPOGRAPHY INITIATED ===\n\n";

    SmartNode* smartHomeHub = new SmartNode("Putri's Smart Home Hub", "Central Root");

    SmartNode* livingRoom = new SmartNode("Living Room Hub", "Room Node");
    SmartNode* kitchen = new SmartNode("Smart Kitchen Area", "Room Node");

    addComponent(smartHomeHub, livingRoom);
    addComponent(smartHomeHub, kitchen);

    SmartNode* tv = new SmartNode("Samsung Neo QLED 8K TV", "Device Leaf");
    SmartNode* ac = new SmartNode("Samsung WindFree Air Conditioner", "Device Leaf");
    SmartNode* fridge = new SmartNode("Samsung Family Hub Refrigerator", "Device Leaf");

    addComponent(livingRoom, tv);
    addComponent(livingRoom, ac);
    addComponent(kitchen, fridge);

    cout << "STATION NETWORK ECOSYSTEM MAPPING:\n";
    cout << "--------------------------------------------------------\n";
    printSmartThingsTree(smartHomeHub);
    cout << "--------------------------------------------------------\n";
    cout << "=== TOPOGRAPHY SYNC COMPLETE - ALL DEVISES ONLINE ===\n";

    return 0;
}
