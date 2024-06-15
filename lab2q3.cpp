#include <iostream>

using namespace std;

// Structure to hold the result
struct MinMax {
    int min;
    int max;
};

// Function to find the minimum and maximum values in an array using a recursive approach
MinMax findMinMax(int arr[], int low, int high, int &steps) {
    MinMax result, leftResult, rightResult;
    
    // If there's only one element
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        steps++; // Increment steps for the base case comparison
        return result;
    }

    // If there are two elements
    if (high == low + 1) {
        steps++; // Increment steps for the first comparison
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        steps++; // Increment steps for the second comparison
        return result;
    }

    // If there are more than two elements
    int mid = (low + high) / 2;
    leftResult = findMinMax(arr, low, mid, steps);
    rightResult = findMinMax(arr, mid + 1, high, steps);

    // Combine results from the left and right halves
    steps++; // Increment steps for the comparison between left and right min
    result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min;
    
    steps++; // Increment steps for the comparison between left and right max
    result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max;

    return result;
}

int main() {
    int arr[] = {1000, 8, 54, 1, 300, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);
    int steps = 0;
    
    MinMax result = findMinMax(arr, 0, n - 1, steps);
    
    cout << "Minimum element is " << result.min << endl;
    cout << "Maximum element is " << result.max << endl;
    cout << "Number of steps is " << steps << endl;
    
    return 0;
}

