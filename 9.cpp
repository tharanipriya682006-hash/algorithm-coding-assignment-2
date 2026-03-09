// educational_bruteforce_otp.cpp
// Educational simulation: generate a 4-digit OTP locally and brute-force it.
// For learning only. Do NOT use against systems you don't own or have permission to test.

#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <thread>
#include <string>

using namespace std;
using namespace std::chrono;

string format4(int x) {
    ostringstream oss;
    oss << setw(4) << setfill('0') << x;
    return oss.str();
}

int main() {
    // Seed RNG
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 9999);

    // Generate a random 4-digit OTP (string for consistent formatting)
    int otpInt = dist(mt);
    string otp = format4(otpInt);

    cout << "Generated (local) OTP: " << otp << "  (this is a local educational simulation)\n\n";

    // Simulate brute-force attempts from 0000 to 9999
    auto start = high_resolution_clock::now();

    int attempts = 0;
    bool found = false;

    for (int guess = 0; guess <= 9999; ++guess) {
        ++attempts;
        string s = format4(guess);

        // Simulate sending the guess to a local verifier (here it's just string compare)
        if (s == otp) {
            auto end = high_resolution_clock::now();
            duration<double> elapsed = end - start;
            cout << "Match found!\n";
            cout << "OTP: " << s << "\n";
            cout << "Attempts: " << attempts << "\n";
            cout << "Elapsed time: " << elapsed.count() << " seconds\n";
            found = true;
            break;
        }

        // OPTIONAL: uncomment to slow down attempts so you can observe runtime behavior
        // this simulates rate-limited environments or network delay
        // if (attempts % 1000 == 0) this_thread::sleep_for(milliseconds(1));
    }

    if (!found) {
        cout << "OTP not found (unexpected).\n";
    }

    return 0;
}
