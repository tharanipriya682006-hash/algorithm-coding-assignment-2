#include <iostream>
#include <vector>
using namespace std;

// Function to swap two elements of any data type
template <typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Recursive function to generate all permutations
template <typename T>
void permute(vector<T> &arr, int l, int r) {
    if (l == r) {
        // Base case: print current permutation
        for (const auto &x : arr) cout << x << " ";
        cout << endl;
    } else {
        for (int i = l; i <= r; i++) {
            // Swap current index with the loop index
            mySwap(arr[l], arr[i]);

            // Recurse for the next index
            permute(arr, l + 1, r);

            // Backtrack to restore original order
            mySwap(arr[l], arr[i]);
        }
    }
}

int main() {
    // Example 1: integers
    vector<int> nums = {1, 2, 3};
    cout << "Permutations of integers:\n";
    permute(nums, 0, nums.size() - 1);

    // Example 2: characters
    vector<char> chars = {'A', 'B', 'C'};
    cout << "\nPermutations of characters:\n";
    permute(chars, 0, chars.size() - 1);

    return 0;
}
