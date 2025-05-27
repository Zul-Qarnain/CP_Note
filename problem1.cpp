#include <iostream>
#include <string>
using namespace std;

class BracketStack {
private:
    char stack[1000];
    int top;

public:
    BracketStack() {
        top = -1;
    }

    void push(char c) {
        if (top < 999) {
            stack[++top] = c;
        }
    }

    char pop() {
        if (top >= 0) {
            return stack[top--];
        }
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }
};

int main() {
    cout << "========== BALANCED BRACKETS CHECKER ==========\n";

    string expression;
    cout << "Enter mathematical expression: ";
    getline(cin, expression);

    BracketStack s;
    int bracketCount = 0;
    int maxDepth = 0;
    int currentDepth = 0;
    bool isBalanced = true;
    char unmatchedType = '\0';
    int unmatchedIndex = -1;

    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];


        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
            bracketCount++;
            currentDepth++;
            if (currentDepth > maxDepth) {
                maxDepth = currentDepth;
            }
        }

        else if (c == ')' || c == '}' || c == ']') {
            bracketCount++;

            if (s.isEmpty()) {
                isBalanced = false;
                unmatchedType = c;
                unmatchedIndex = i;
                break;
            }

            char top = s.pop();
            currentDepth--;

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                isBalanced = false;
                unmatchedType = c;
                unmatchedIndex = i;
                break;
            }
        }
    }
    if (isBalanced && !s.isEmpty()) {
        isBalanced = false;
    }

    cout << "\nResults:" << endl;
    cout << "Expression: " << expression << endl;
    cout << "Total brackets: " << bracketCount << endl;
    cout << "Maximum depth: " << maxDepth << endl;

    if (isBalanced) {
        cout << "Status: Balanced" << endl;
    } else {
        cout << "Status: Not Balanced" << endl;
        if (unmatchedType != '\0') {
            cout << "First unmatched bracket: '" << unmatchedType
                 << "' at position " << unmatchedIndex << endl;
        } else {
            cout << "Unmatched opening bracket(s) found" << endl;
        }
    }

    return 0;
}
