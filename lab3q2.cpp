#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A structure to represent an item with weight and value
struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparison function to sort items by value-to-weight ratio
bool cmp(const Item& a, const Item& b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to solve the Fractional Knapsack problem using a greedy algorithm
double fractionalKnapsack(int W, vector<Item>& items, int& steps) {
    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), cmp);
    
    double totalValue = 0.0;
    steps = 0; // Initialize steps count

    for (size_t i = 0; i < items.size(); ++i) {
        const Item& item = items[i];
        ++steps; // Count the step for each iteration
        if (W == 0) break;

        if (item.weight <= W) {
            // If the item can be added completely
            W -= item.weight;
            totalValue += item.value;
        } else {
            // If the item cannot be added completely
            totalValue += item.value * ((double)W / item.weight);
            W = 0;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items;
    items.push_back(Item(50, 20));
    items.push_back(Item(90, 30));
    items.push_back(Item(110, 40));
    items.push_back(Item(120, 50));
    int W = 50;
    int steps = 0;

    double max_value = fractionalKnapsack(W, items, steps);

    cout << "Total steps taken to solve the Fractional Knapsack problem: " << steps << endl;
    cout << "Maximum value that can be obtained: " << max_value << endl;

    return 0;
}






