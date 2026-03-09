#include <iostream>
#include <vector>
using namespace std;

// Function to calculate total weight and value of a given combination
void evaluateCombination(const vector<int>& weight, const vector<int>& value,
                         const vector<int>& combination, int capacity,
                         int& maxValue, vector<int>& bestCombination) {
    int totalWeight = 0, totalValue = 0;
    for (int i : combination) {
        totalWeight += weight[i];
        totalValue += value[i];
    }

    if (totalWeight <= capacity && totalValue > maxValue) {
        maxValue = totalValue;
        bestCombination = combination;
    }
}

// Recursive function to generate combinations of given size
void generateCombinations(const vector<int>& items, int start, int k,
                          vector<int>& current, const vector<int>& weight,
                          const vector<int>& value, int capacity,
                          int& maxValue, vector<int>& bestCombination) {
    if (current.size() == k) {
        evaluateCombination(weight, value, current, capacity, maxValue, bestCombination);
        return;
    }

    for (int i = start; i < items.size(); i++) {
        current.push_back(items[i]);
        generateCombinations(items, i + 1, k, current, weight, value, capacity, maxValue, bestCombination);
        current.pop_back();
    }
}

int main() {
    const int n = 6;
    vector<int> weight = {2, 3, 4, 5, 9, 7};
    vector<int> value  = {3, 4, 8, 8, 10, 6};
    int capacity = 15;

    vector<int> items;
    for (int i = 0; i < n; i++)
        items.push_back(i);

    int maxValue = 0;
    vector<int> bestCombination;

    cout << "Evaluating all combinations...\n";

    // Generate combinations of all possible sizes (1 to n)
    for (int k = 1; k <= n; k++) {
        vector<int> current;
        generateCombinations(items, 0, k, current, weight, value, capacity, maxValue, bestCombination);
    }

    // Display results
    cout << "\nMaximum Value: " << maxValue << endl;
    cout << "Items included (0-based index): ";
    for (int i : bestCombination)
        cout << i << " ";
    cout << endl;

    return 0;
}
