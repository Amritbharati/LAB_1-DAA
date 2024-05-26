#include <iostream>
using namespace std;

// Function to perform sequential search and count steps
int sequentialSearch(int arr[], int size, int key, int &steps) {
    steps = 0;
    for (int i = 0; i < size; ++i) {
        steps++;
        if (arr[i] == key)
            return i; // Return index if key is found
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key, steps;

    cout << "Enter the number to search: ";
    cin >> key;

    int index = sequentialSearch(arr, size, key, steps);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found in the array" << endl;

    cout << "Number of steps taken: " << steps << endl;

    return 0;
}
