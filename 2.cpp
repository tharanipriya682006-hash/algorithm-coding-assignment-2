#include <iostream>
#include <vector>
using namespace std;

// Recursive helper function to generate combinations
template <typename T>
void combineHelper(vector<T> &arr, int start, int k, vector<T> &current) {
    // Base case: when combination of size k is formed
    if (current.size() == k) {
        for (const auto &x : current) cout << x << " ";
        cout << endl;
        return;
    }

    // Recursive case: include or exclude elements
    for (int i = start; i < arr.size(); i++) {
        // Choose the current element
        current.push_back(arr[i]);
        
        // Move to next element
        combineHelper(arr, i + 1, k, current);
        
        // Backtrack: remove last added element
        current.pop_back();
    }
}

// Wrapper function
template <typename T>
void generateCombinations(vector<T> &arr, int k) {
    vector<T> current;
    combineHelper(arr, 0, k, current);
}

int main() {
    // Example 1: integers
    vector<int> nums = {1, 2, 3, 4};
    int k1 = 2;
    cout << "Combinations of integers (k = " << k1 << "):\n";
    generateCombinations(nums, k1);

    // Example 2: characters
    vector<char> chars = {'A', 'B', 'C', 'D'};
    int k2 = 3;
    cout << "\nCombinations of characters (k = " << k2 << "):\n";
    generateCombinations(chars, k2);

    return 0;
}
