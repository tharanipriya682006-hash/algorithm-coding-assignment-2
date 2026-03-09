#include <iostream>
#include <vector>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

// Function to convert integer to binary representation (as a vector)
vector<int> intToBinary(int n) {
    vector<int> binary;
    if (n == 0) {
        binary.push_back(0);
        return binary;
    }
    while (n > 0) {
        binary.push_back(n % 2); // store remainder (LSB)
        n /= 2;
    }
    // binary vector currently holds bits in reverse order (LSB first)
    return binary;
}

int main() {
    srand(time(0));  // seed for random number generator

    int num;
    cout << "Enter an integer: ";
    cin >> num;

    // Convert to binary
    vector<int> binary = intToBinary(num);

    cout << "Binary equivalent of " << num << " is: ";
    for (int i = binary.size() - 1; i >= 0; i--)
        cout << binary[i];
    cout << endl;

    // Pick a random position between 0 and binary.size()-1
    int pos = rand() % binary.size();
    cout << "Random bit position chosen: " << pos << endl;

    // Check the bit at that position
    int bitValue = binary[pos];
    cout << "Bit at position " << pos << " is: " << bitValue << endl;

    // Print true if bit = 1, false if bit = 0
    if (bitValue == 1)
        cout << "Output: true" << endl;
    else
        cout << "Output: false" << endl;

    return 0;
}
