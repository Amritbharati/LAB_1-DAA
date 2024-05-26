#include <iostream>
using namespace std;


int gcd(int a, int b) {
    int step = 1;  // Step counter
    cout << "Step " << step++ << ": Initial values - a = " << a << ", b = " << b << endl;
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        cout << "Step " << step++ << ": Updated values - a = " << a << ", b = " << b << endl;
    }
    
    cout << "GCD is " << a << endl;
    return a;
}

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    int result = gcd(a, b);
    cout << "The GCD of " << a << " and " << b << " is: " << result << endl;

    return 0;
}
