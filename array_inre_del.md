Here is the **raw C++ code** for **insertion and deletion** in **1D and 2D arrays** without using pointers or vectors.

---

## **1D Array Insertion and Deletion**
```cpp
#include <iostream>
using namespace std;

void insertElement(int arr[], int &n, int capacity, int pos, int value) {
    if (n >= capacity) {
        cout << "Array is full. Cannot insert." << endl;
        return;
    }
    if (pos < 0 || pos > n) {
        cout << "Invalid position." << endl;
        return;
    }

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1]; // Shift elements right
    }
    arr[pos] = value;
    n++; // Increase array size
}

void deleteElement(int arr[], int &n, int pos) {
    if (n == 0) {
        cout << "Array is empty. Cannot delete." << endl;
        return;
    }
    if (pos < 0 || pos >= n) {
        cout << "Invalid position." << endl;
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1]; // Shift elements left
    }
    n--; // Decrease array size
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int capacity = 10;
    int arr[capacity] = {1, 2, 3, 4, 5}; 
    int size = 5;

    cout << "Original Array: ";
    displayArray(arr, size);

    insertElement(arr, size, capacity, 2, 99);
    cout << "After Insertion at index 2: ";
    displayArray(arr, size);

    deleteElement(arr, size, 3);
    cout << "After Deletion at index 3: ";
    displayArray(arr, size);

    return 0;
}
```

---

## **2D Array Insertion and Deletion**
```cpp
#include <iostream>
using namespace std;

void insertElement(int arr[][5], int &rows, int cols, int rowPos, int colPos, int value) {
    if (rowPos < 0 || rowPos >= rows || colPos < 0 || colPos >= cols) {
        cout << "Invalid position." << endl;
        return;
    }
    arr[rowPos][colPos] = value;
}

void deleteElement(int arr[][5], int &rows, int cols, int rowPos, int colPos) {
    if (rowPos < 0 || rowPos >= rows || colPos < 0 || colPos >= cols) {
        cout << "Invalid position." << endl;
        return;
    }
    arr[rowPos][colPos] = 0; // Set to 0 (or another default value)
}

void displayArray(int arr[][5], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int rows = 5, cols = 5;

    cout << "Original 2D Array: " << endl;
    displayArray(arr, rows, cols);

    insertElement(arr, rows, cols, 2, 2, 99);
    cout << "After Insertion at (2,2):" << endl;
    displayArray(arr, rows, cols);

    deleteElement(arr, rows, cols, 3, 3);
    cout << "After Deletion at (3,3):" << endl;
    displayArray(arr, rows, cols);

    return 0;
}
```

---

### **Explanation**
1. **1D Array:**
   - Insertion shifts elements to the right before inserting a new value.
   - Deletion shifts elements to the left after removing a value.
   
2. **2D Array:**
   - Directly modifies an element at a specific position.
   - Deletion simply resets the value to `0` (or any placeholder).

Let me know if you need modifications! 🚀
