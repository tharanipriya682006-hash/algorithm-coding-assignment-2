#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Utility function to make both numbers equal length by padding with leading zeros
string makeEqualLength(string a, string b) {
    int len1 = a.size();
    int len2 = b.size();
    if (len1 < len2)
        a.insert(0, len2 - len1, '0');
    else if (len2 < len1)
        b.insert(0, len1 - len2, '0');
    return (a.size() > b.size()) ? a : b; // dummy return to keep both equal
}

// Utility function to add two numeric strings
string addStrings(string a, string b) {
    makeEqualLength(a, b);
    int carry = 0;
    string result = "";
    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    if (carry)
        result.push_back(carry + '0');
    reverse(result.begin(), result.end());
    return result;
}

// Utility function to subtract b from a (assuming a >= b)
string subtractStrings(string a, string b) {
    makeEqualLength(a, b);
    int borrow = 0;
    string result = "";
    for (int i = a.size() - 1; i >= 0; i--) {
        int diff = (a[i] - '0') - (b[i] - '0') - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else
            borrow = 0;
        result.push_back(diff + '0');
    }
    reverse(result.begin(), result.end());
    // remove leading zeros
    result.erase(0, result.find_first_not_of('0'));
    if (result.empty()) result = "0";
    return result;
}

// Karatsuba recursive function
string karatsubaMultiply(string X, string Y) {
    makeEqualLength(X, Y);
    int n = X.size();

    // Base case for single-digit numbers
    if (n == 1) {
        int prod = (X[0] - '0') * (Y[0] - '0');
        return to_string(prod);
    }

    int m = n / 2;

    // Split strings
    string Xl = X.substr(0, n - m);
    string Xr = X.substr(n - m);
    string Yl = Y.substr(0, n - m);
    string Yr = Y.substr(n - m);

    // Recursive steps
    string P1 = karatsubaMultiply(Xl, Yl);
    string P2 = karatsubaMultiply(Xr, Yr);
    string P3 = karatsubaMultiply(addStrings(Xl, Xr), addStrings(Yl, Yr));

    // P3 - P1 - P2
    string middle = subtractStrings(subtractStrings(P3, P1), P2);

    // Assemble final result: P1 * 10^(2*m) + middle * 10^m + P2
    string result = addStrings(addStrings(P1 + string(2 * m, '0'),
                                          middle + string(m, '0')),
                               P2);

    // Remove leading zeros
    result.erase(0, result.find_first_not_of('0'));
    if (result.empty()) result = "0";

    return result;
}

int main() {
    string num1, num2;
    cout << "Enter first long integer: ";
    cin >> num1;
    cout << "Enter second long integer: ";
    cin >> num2;

    // Compute product using Karatsuba algorithm
    string product = karatsubaMultiply(num1, num2);

    cout << "\nProduct = " << product << endl;
    return 0;
}
