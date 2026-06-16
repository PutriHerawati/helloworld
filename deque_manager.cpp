#include <iostream>
#include <deque>

using namespace std;

int main() {
    // Creating a double-ended queue (deque) of integers
    deque<int> dq;

    cout << "=== DOUBLE-ENDED QUEUE (DEQUE) MANAGER ===" << endl;

    // Inserting elements at both ends
    dq.push_back(10);  
    dq.push_back(20);  
    dq.push_front(30); 

    // Displaying initial queue elements
    cout << "Initial Deque elements after insertions: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    // Removing elements from both ends
    dq.pop_front(); 
    dq.pop_back();  

    // Displaying final queue elements
    cout << "Final Deque elements after deletions : ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    cout << "------------------------------------------" << endl;
    cout << "Program finished successfully!" << endl;

    return 0;
}
