#include <iostream>
#include <string>
using namespace std;
class CustomerQueue {
private:
    string queue[100];
    int front, rear, count;
public:
    CustomerQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }
    void enqueue(string customer) {
        if (count < 100) {
            rear = (rear + 1) % 100;
            queue[rear] = customer;
            count++;
        }
    }
    string dequeue() {
        if (count > 0) {
            string customer = queue[front];
            front = (front + 1) % 100;
            count--;
            return customer;
        }
        return "";
    }
    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }
};

int main() {
    cout << "========== CUSTOMER SERVICE SYSTEM ==========\n";

    CustomerQueue vipQueue, regularQueue;
    cout << "Adding initial customers...\n";
    vipQueue.enqueue("Alice");
    vipQueue.enqueue("Bob");
    regularQueue.enqueue("Charlie");
    regularQueue.enqueue("Diana");
    vipQueue.enqueue("Eve");
    regularQueue.enqueue("Frank");
    regularQueue.enqueue("Grace");

    cout << "Initial customers added:" << endl;
    cout << "VIP Queue: Alice, Bob, Eve" << endl;
    cout << "Regular Queue: Charlie, Diana, Frank, Grace" << endl;

    string name, type;
    cout << "\nAdd more customers dynamically:" << endl;
    cout << "(Type 'exit' as name to stop adding customers)\n";

    while (true) {
        cout << "Enter customer name: ";
        getline(cin, name);
        if (name == "exit") {
            break;
        }
        cout << "Enter customer type (VIP/Regular): ";
        getline(cin, type);

        if (type == "VIP" || type == "vip") {
            vipQueue.enqueue(name);
            cout << name << " added to VIP queue" << endl;
        } else {
            regularQueue.enqueue(name);
            cout << name << " added to Regular queue" << endl;
        }
    }
    cout << "\n========== SERVING CUSTOMERS ==========\n";
    cout << "Service logic: VIP -> Regular -> VIP -> Regular...\n";

    int totalServed = 0;

    while (!vipQueue.isEmpty() || !regularQueue.isEmpty()) {
        if (!vipQueue.isEmpty()) {
            string customer = vipQueue.dequeue();
            cout << "Serving VIP customer: " << customer << endl;
            totalServed++;
        }
        if (!regularQueue.isEmpty()) {
            string customer = regularQueue.dequeue();
            cout << "Serving Regular customer: " << customer << endl;
            totalServed++;
        }
    }
    cout << "\n========== SERVICE COMPLETED ==========\n";
    cout << "Total customers served: " << totalServed << endl;
    cout << "VIP queue remaining customers: " << vipQueue.size() << endl;
    cout << "Regular queue remaining customers: " << regularQueue.size() << endl;
    cout << "VIP queue is empty: " << (vipQueue.isEmpty() ? "Yes" : "No") << endl;
    cout << "Regular queue is empty: " << (regularQueue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
