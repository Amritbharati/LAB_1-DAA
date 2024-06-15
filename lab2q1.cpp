/*
 * Program: Insertion Sort
 *
 * Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands.
 * The array is virtually split into a sorted and an unsorted part.
 * Values from the unsorted part are picked and placed at the correct position in the sorted part.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 *
 */

#include <iostream>
using namespace std;

void insertionSort(int[], int, int&);

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int stepCount = 0;
    insertionSort(arr, n, stepCount);

    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Total number of steps: " << stepCount << endl;

    return 0;
}

void insertionSort(int arr[], int size, int& stepCount)
{
    int temp, j;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
            stepCount++; // Counting each comparison and shift
        }
        arr[j + 1] = temp;
        stepCount++; // Counting the insertion step
    }
}

