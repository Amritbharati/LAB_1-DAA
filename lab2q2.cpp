/*
 * Program: Selection Sort Program
 *
 * Selection sort is a sorting algorithm that sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 */

#include <iostream>
using namespace std;

void selectionSort(int[], int, int&);

int main()
{
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int stepCount = 0;
    selectionSort(arr, n, stepCount);

    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Total number of steps: " << stepCount << endl;

    return 0;
}

void selectionSort(int arr[], int size, int& stepCount)
{
    int minIndex, temp;
    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            stepCount++; // Counting each comparison
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // Swap if minIndex has changed
        if (minIndex != i) {
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
            stepCount++; // Counting each swap
        }
    }
}

