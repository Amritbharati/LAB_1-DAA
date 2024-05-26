//write a program to find the factorial of given number and also compute number  of steps
#include <iostream>
using namespace std;

// Function to calculate factorial and count steps
unsigned long long factorial(int n, int &steps) {
    unsigned long long result = 1;
    steps = 0;
    for(int i = 1; i <= n; ++i) {
        result *= i;
        steps++;
    }
    return result;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if(number < 0) {
        cout << "Factorial of negative numbers doesn't exist." << endl;
        return 1;
    }

    int steps;
    unsigned long long fact = factorial(number, steps);

    cout << "Factorial of " << number << " is " << fact << endl;
    cout << "Number of steps taken: " << steps << endl;

    return 0;
}
