#include <iostream>
#include <string>
using namespace std;
class Stack {
private:
    static const int MAX_SIZE = 100;
    string data[MAX_SIZE];
    int top;
public:
    Stack() : top(-1) {}
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == MAX_SIZE - 1;
    }
    void push(string item) {
        if (!isFull()) {
            data[++top] = item;
        }
    }

    string pop() {
        if (!isEmpty()) {
            return data[top--];
        }
        return "";
    }

    string peek() {
        if (!isEmpty()) {
            return data[top];
        }
        return "";
    }

    int size() {
        return top + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << "  " << data[i] << endl;
        }
    }
};

class Queue {
private:
    static const int MAX_SIZE = 100;
    string data[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    Queue() : front(0), rear(-1), count(0) {}

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX_SIZE;
    }

    void enqueue(string item) {
        if (!isFull()) {
            rear = (rear + 1) % MAX_SIZE;
            data[rear] = item;
            count++;
        }
    }

    string dequeue() {
        if (!isEmpty()) {
            string item = data[front];
            front = (front + 1) % MAX_SIZE;
            count--;
            return item;
        }
        return "";
    }

    int size() {
        return count;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int current = front;
        for (int i = 0; i < count; i++) {
            cout << "  " << data[current] << endl;
            current = (current + 1) % MAX_SIZE;
        }
    }
};

class Browser {
private:
    Stack historyStack;
    Stack forwardStack;
    Queue downloadQueue;
    string currentPage;

public:
    Browser() : currentPage("") {}

    void visitWebsite(string url) {
        if (currentPage != "") {
            historyStack.push(currentPage);
        }
        currentPage = url;

        while (!forwardStack.isEmpty()) {
            forwardStack.pop();
        }
        cout << "Visited: " << url << endl;
    }

    void goBack() {
        if (!historyStack.isEmpty()) {
            forwardStack.push(currentPage);
            currentPage = historyStack.pop();
            cout << "Went back to: " << currentPage << endl;
        } else {
            cout << "Cannot go back - no history available" << endl;
        }
    }

    void goForward() {
        if (!forwardStack.isEmpty()) {
            historyStack.push(currentPage);
            currentPage = forwardStack.pop();
            cout << "Went forward to: " << currentPage << endl;
        } else {
            cout << "Cannot go forward - no forward history available" << endl;
        }
    }

    void addDownload(string filename) {
        downloadQueue.enqueue(filename);
        cout << "Added to download queue: " << filename << endl;
    }

    void processDownloads() {
        cout << endl << "=== Processing Downloads ===" << endl;
        int downloadCount = 1;
        while (!downloadQueue.isEmpty()) {
            string filename = downloadQueue.dequeue();
            cout << "Download " << downloadCount++ << ": " << filename
                 << " - Download complete!" << endl;
        }
        if (downloadCount == 1) {
            cout << "No downloads to process." << endl;
        }
    }

    string getCurrentPage() {
        return currentPage;
    }

    void displayNavigationState() {
        cout << endl << "=== Browser Navigation State ===" << endl;
        cout << "Current page: " << (currentPage.empty() ? "None" : currentPage) << endl;

        cout << endl << "Back history (most recent first):" << endl;
        if (historyStack.isEmpty()) {
            cout << "  No back history" << endl;
        } else {
            historyStack.display();
        }

        cout << endl << "Forward history (next pages):" << endl;
        if (forwardStack.isEmpty()) {
            cout << "  No forward history" << endl;
        } else {
            forwardStack.display();
        }

        cout << endl << "Remaining downloads:" << endl;
        if (downloadQueue.isEmpty()) {
            cout << "  No pending downloads" << endl;
        } else {
            downloadQueue.display();
        }
    }
};

void displayMenu() {
    cout << endl << "=== Browser Navigation Menu ===" << endl;
    cout << "1. Visit website" << endl;
    cout << "2. Go back" << endl;
    cout << "3. Go forward" << endl;
    cout << "4. Add download" << endl;
    cout << "5. Process downloads" << endl;
    cout << "6. Show navigation state" << endl;
    cout << "7. Run demo simulation" << endl;
    cout << "8. Exit" << endl;
    cout << "Choose an option: ";
}

void runDemoSimulation(Browser& browser) {
    cout << endl << "=== Running Demo Simulation ===" << endl;

    cout << endl << "1. Visiting websites:" << endl;
    browser.visitWebsite("google.com");
    browser.visitWebsite("youtube.com");
    browser.visitWebsite("github.com");
    browser.visitWebsite("stackoverflow.com");
    browser.visitWebsite("wikipedia.org");


    cout << endl << "2. Adding downloads:" << endl;
    browser.addDownload("document.pdf");
    browser.addDownload("image.jpg");
    browser.addDownload("software.zip");
    browser.addDownload("music.mp3");


    cout << endl << "3. Navigation - Going back:" << endl;
    browser.goBack();
    browser.goBack();
    browser.goBack();


    cout << endl << "4. Navigation - Going forward:" << endl;
    browser.goForward();
    browser.goForward();


    cout << endl << "5. Visiting new website (clears forward history):" << endl;
    browser.visitWebsite("facebook.com");


    cout << endl << "6. Attempting to go forward (should fail):" << endl;
    browser.goForward();


    cout << endl << "7. Processing downloads:" << endl;
    browser.processDownloads();

    browser.displayNavigationState();
}

int main() {
    Browser browser;
    int choice;
    string input;

    cout << "=== Web Browser Navigation Simulation ===" << endl;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "Enter website URL: ";
                getline(cin, input);
                browser.visitWebsite(input);
                break;
            }
            case 2: {
                browser.goBack();
                break;
            }
            case 3: {
                browser.goForward();
                break;
            }
            case 4: {
                cout << "Enter filename to download: ";
                getline(cin, input);
                browser.addDownload(input);
                break;
            }
            case 5: {
                browser.processDownloads();
                break;
            }
            case 6: {
                browser.displayNavigationState();
                break;
            }
            case 7: {
                runDemoSimulation(browser);
                break;
            }
            case 8: {
                cout << "Exiting browser simulation. Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid option. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}
