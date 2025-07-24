#include <iostream>
using namespace std;

void merge(int *arr, int low, int high, int mid) {
    int i = low, j = mid + 1, k = 0;
    int c[high - low + 1];
    
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            c[k++] = arr[i++];
        } else {
            c[k++] = arr[j++];
        }
    }
    
    while (i <= mid) {
        c[k++] = arr[i++];
    }
    
    while (j <= high) {
        c[k++] = arr[j++];
    }
    
    for (i = low; i <= high; i++) {
        arr[i] = c[i - low];
    }
}

void merge_sort(int *arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    merge_sort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}