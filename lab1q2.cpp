// wap to find the fibonacci series and also compute no of step.
#include <iostream>

int fibonacci(int n, int& steps) {
    steps++;
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1, steps) + fibonacci(n - 2, steps);
}

int main() {
    int n;
    std::cout << "Enter the number of terms in Fibonacci series: ";
    std::cin >> n;

    int steps = 0;
    std::cout << "Fibonacci Series: ";
    
    for (int i = 0; i < n; ++i) {
        int fib = fibonacci(i, steps);
        std::cout << fib << " ";
    }
    std::cout << std::endl;

    std::cout << "Number of steps taken: " << steps << std::endl;

    return 0;
}
