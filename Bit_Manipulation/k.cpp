#include <iostream>
#include <string>
using namespace std;

// Function to calculate the type of a string
string getType(const string& s) {
    if (s.empty()) return "";
    if (s.size() == 1) return string(2, s[0]); // "aa" for single character
    return string(1, s[0]) + s.back(); // First and last characters
}

// Function to find the maximum operations to retain the type
int maxOperationsToRetainType(const string& s) {
    string initialType = getType(s);
    int n = s.size();

    // Two pointers to find the valid range for substrings
    int left = 0, right = n - 1;

    // Find the leftmost index where the initial type's first character is present
    while (left < n && s[left] != initialType[0]) {
        ++left;
    }

    // Find the rightmost index where the initial type's second character is present
    while (right >= 0 && s[right] != initialType[1]) {
        --right;
    }

    // If no valid substring exists, return 0
    if (left >= right) return 0;

    // The range [left, right] defines the smallest valid substring
    // Maximum operations = total characters outside this range
    return left + (n - 1 - right);
}

int main() {
    string s;
    cout << "Enter the product identifier string: ";
    cin >> s;

    int result = maxOperationsToRetainType(s);
    cout << "Maximum operations to retain type: " << result << endl;

    return 0;
}
