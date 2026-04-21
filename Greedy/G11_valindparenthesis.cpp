#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(3n) the worst case, every '*' can be replaced with '(', ')' or
//  an empty string. For each '*', we have 3 choices, so with k '*' characters,
//   we make 3k recursive calls. If the input string has length n, and all
//    are '*', the time complexity becomes exponential.

// Space Complexity: O(n) ,This is due to the maximum depth of the recursive call stack. 
// At most, there are n recursive calls at any time (one for each character).


class Solution {
public:
    // function to check if string is valid by trying all possibilities for '*'
    bool isValid(string& s, int i, int open) {
        // If open becomes negative, the string is invalid
        if (open < 0) return false;

        // If we reach the end, check if all opens are closed
        if (i == s.length()) return open == 0;

        // If current character is '(', treat it as an opening bracket
        if (s[i] == '(') {
            return isValid(s, i + 1, open + 1);
        } 
        // If current character is ')', treat it as a closing bracket
        else if (s[i] == ')') {
            return isValid(s, i + 1, open - 1);
        } 
        // If character is '*', try all 3 options
        else {
              // Treat '*' as empty
              // Treat '*' as '('
              // Treat '*' as ')'
            return isValid(s, i + 1, open) ||       
                   isValid(s, i + 1, open + 1) ||    
                   isValid(s, i + 1, open - 1);      
        }
    }
};
// Driver Code
int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    Solution sol;
    if (sol.isValid(s, 0, 0)) {
        cout << "Valid parenthesis string\n";
    } else {
        cout << "Invalid parenthesis string\n";
    }

    return 0;
}
