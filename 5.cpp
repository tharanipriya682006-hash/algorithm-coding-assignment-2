#include <iostream>
#include <vector>
#include <cmath> // for pow()
using namespace std;

int main() {
    // Number of items
    const int n = 6;

    // Weights and values of the items
    vector<int> weight = {2, 3, 4, 5, 9, 7};
    vector<int> value  = {3, 4, 8, 8, 10, 6};

    int capacity = 15; // maximum weight the knapsack can hold

    int maxValue = 0;
    int bestCombination = 0;

    // Total possible combinations = 2^n
    int totalComb = 1 << n;  // equivalent to 2^n

    cout << "Evaluating all combinations...\n";

    for (int mask = 0; mask < totalComb; mask++) {
        int totalWeight = 0;
        int totalValue = 0;

        // Use binary representation to decide inclusion/exclusion
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {  // if bit i is set → include item i
                totalWeight += weight[i];
                totalValue += value[i];
            }
        }

        // Check if this combination is valid and better
        if (totalWeight <= capacity && totalValue > maxValue) {
            maxValue = totalValue;
            bestCombination = mask;
        }
    }

    // Display results
    cout << "\nMaximum Value: " << maxValue << endl;
    cout << "Items included (0-based index): ";

    for (int i = 0; i < n; i++) {
        if (bestCombination & (1 << i))
            cout << i << " ";
    }
    cout << endl;

    // Display binary representation of best combination
    cout << "Binary representation of best combination: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << ((bestCombination >> i) & 1);
    }
    cout << endl;

    return 0;
}
