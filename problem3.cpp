#include <iostream>
#include <string>
using namespace std;

class ActionStack {
private:
    string stack[1000];
    int top;
public:
    ActionStack() {
        top = -1;
    }
    void push(string action) {
        if (top < 999) {
            stack[++top] = action;}}
    string pop() {
        if (top >= 0) {
            return stack[top--];
        }
        return ""; }

    bool isEmpty() {
        return top == -1;}
    int size() {return top + 1;}

    void displayActions() {
        if (isEmpty()) {
            cout << "No actions remaining in the editor." << endl;
            return;}
        cout << "Remaining actions (from oldest to newest):" << endl;
        for (int i = 0; i <= top; i++) {
            cout << (i + 1) << ". " << stack[i] << endl;}}};

int main() {
    cout << "========== TEXT EDITOR UNDO SIMULATION ==========\n";
    ActionStack actions;
    string action;
    cout << "Enter text editor actions (type 'done' when finished):\n";
    cout << "Examples: 'Type: Hello', 'Delete: 3 characters', 'Bold: selected text', 'Italic: word'\n";
    int actionCount = 0;
    while (true) {
        cout << "Action " << (actionCount + 1) << ": ";
        getline(cin, action);
        if (action == "done") {break;}
        actions.push(action);
        actionCount++;
        cout << "Added: " << action << endl;}
    if (actions.isEmpty()) {
        cout << "No actions were entered. Exiting..." << endl;
        return 0; }
   cout << "\nTotal actions recorded: " << actions.size() << endl;
    cout << "\nCurrent editor state:" << endl;
    actions.displayActions();

    int undoCount;
    cout << "\nHow many undo operations do you want to perform? ";
    cin >> undoCount;

    if (undoCount <= 0) {
        cout << "No undo operations requested." << endl;
        return 0;
    }

    cout << "\n========== PERFORMING UNDO OPERATIONS ==========\n";

    for (int i = 0; i < undoCount; i++) {
        string undoneAction = actions.pop();

        if (undoneAction != "") {
            cout << "Undo " << (i + 1) << ": Reversed '" << undoneAction << "'" << endl;
        } else {
            cout << "Undo " << (i + 1) << ": No more actions to undo!" << endl;
            break;
        }
    }

    cout << "\n========== FINAL EDITOR STATE ==========\n";
    cout << "Actions remaining after undo operations:" << endl;
    actions.displayActions();

    cout << "\nTotal actions remaining: " << actions.size() << endl;

    return 0;
}
