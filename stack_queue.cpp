#include <iostream>
using namespace std;

#define SIZE 5

// ==================== Stack Class ====================
class Stack {
private:
    int arr[SIZE];
    int top;

public:
    Stack() { top = -1; }

    void push(int val) {
        if (top == SIZE - 1) {
            cout << "Stack Overflow. Cannot push " << val << endl;
            return;
        }
        arr[++top] = val;
        cout << "Pushed " << val << " onto the stack." << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow. Nothing to pop." << endl;
            return;
        }
        cout << "Popped " << arr[top--] << " from the stack." << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (Top to Bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }

    void displayReverse() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (Bottom to Top): ";
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ==================== Queue Class ====================
class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int val) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow. Cannot enqueue " << val << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = val;
        cout << "Enqueued " << val << " to the queue." << endl;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow. Nothing to dequeue." << endl;
            return;
        }
        cout << "Dequeued " << arr[front++] << " from the queue." << endl;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue (Front to Rear): ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "Queue (Rear to Front): ";
        for (int i = rear; i >= front; i--)
            cout << arr[i] << " ";
        cout << endl;

    }

    /*void displayReverse() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue (Rear to Front): ";
        for (int i = rear; i >= front; i--)
            cout << arr[i] << " ";
        cout << endl;
    }*/
};

// ==================== Main Function ====================
int main() {
    Stack s;
    Queue q;

    cout << "\n--- Stack Operations ---\n";
    s.pop(); // Underflow
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60); // Overflow
    s.display();
    s.displayReverse();
    s.pop();
    s.display();

    cout << "\n--- Queue Operations ---\n";
    q.dequeue(); // Underflow
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6); // Overflow
    q.display();
    //q.displayReverse();
    q.dequeue();
    q.display();

    return 0;
}
