#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to validate the string using greedy approach
    bool isValid(string s) {
        // Track minimum and maximum open brackets
        int minOpen = 0, maxOpen = 0;

        // Traverse each character in the string
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else {
                // Treat '*' as '(', ')' or ''
                minOpen--;
                maxOpen++;
            }

            // If maxOpen goes negative, too many closing brackets
            if (maxOpen < 0) return false;

            // minOpen can't be negative
            minOpen = max(minOpen, 0);
        }

        // String is valid if all opens are closed
        return minOpen == 0;
    }
};

// Driver code
int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    Solution sol;
    if (sol.isValid(s)) {
        cout << "Valid parenthesis string" << endl;
    } else {
        cout << "Invalid parenthesis string" << endl;
    }
    return 0;
}
