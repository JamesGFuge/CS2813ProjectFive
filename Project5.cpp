// Coding Assignment 5 - C++ Template

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;


// Step 1: Total counting
long long count_total_strings(int k) {

    // There are 3 choices for each position.
    long long total = 1;
    for (int i = 0; i < k; ++i) {
        total *= 3;
    }
    return total;
}


// Step 2: Count strings with no consecutive identical characters
long long count_no_consecutive_same(int k) {

    if (k <= 0) {
        return 0;
    }

    // First character: 3 choices.
    // Each subsequent character cannot equal the previous one: 2 choices each.
    long long count = 3;
    for (int i = 1; i < k; ++i) {
        count *= 2;
    }
    return count;
}


// Step 3: Probability computation
double prob_no_consecutive_same(int k) {

    long long total = count_total_strings(k);
    if (total == 0) {
        return 0.0;
    }
    long long no_consec = count_no_consecutive_same(k);
    return static_cast<double>(no_consec) / static_cast<double>(total);
}


// Helper function for Step 4:
// Count strings of length k that contain NO "CC"
long long count_no_CC(int k) {

    if (k <= 0) {
        return 0;
    }

    long long endC = 1;      // strings of length 1 ending in 'C'
    long long endNotC = 2;   // strings of length 1 ending in 'A' or 'B'

    for (int i = 2; i <= k; ++i) {
        long long nextEndC = endNotC;          // append C to a non-C ending string
        long long nextEndNotC = 2 * (endC + endNotC); // append A or B to any string

        endC = nextEndC;
        endNotC = nextEndNotC;
    }

    return endC + endNotC;
}


// Step 4: Count strings that contain at least one "CC"
long long count_strings_with_CC(int k) {

    long long total = count_total_strings(k);
    long long noCC = count_no_CC(k);
    return total - noCC;
}


int main() {

    int k;

    cout << "Enter the value of k: ";
    cin >> k;

    // Optional: basic validity check
    if (k < 1 || k > 20) {
        cout << "Error: k must be between 1 and 20." << endl;
        return 1;
    }

    // Step 1
    long long total_strings = count_total_strings(k);

    // Step 2
    long long no_consecutive_same = count_no_consecutive_same(k);

    // Step 3
    double probability = prob_no_consecutive_same(k);

    // Step 4
    long long with_CC = count_strings_with_CC(k);

    // Output
    cout << "Total Strings = " << total_strings << endl;
    cout << "No Consecutive Same = " << no_consecutive_same << endl;
    cout << fixed << setprecision(4);
    cout << "Probability = " << probability << endl;
    cout << "Strings with \"CC\" = " << with_CC << endl;

    return 0;
}