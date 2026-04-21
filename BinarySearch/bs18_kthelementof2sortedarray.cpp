/*
@FusionArcs
2 years ago
finally, the mystery of why low and high needs to be corrected for this solution?
Let's take an example, m = 3, n = 10, k = 12
If we keep low = 0, and high = 3
then mid1 = 1;
low = 0 means we don't pick any element from the first array, and now the remaining 
elements need to be picked from the second array.
mid2 = (k - mid1) = 12 - 1 = 11 ???? but there are only 10 elements in the second array
Hence we can't start our search when we pick no elements from the first array.
So our low must be max(k - n, 0) [no of elements  at least need to pick for 1st array]
Similarly, for high, we have to reduce the search space such that it can handle low K values.

Note: this issue doesn't occur in the median problem because we guaranteed to
 split the search space in half every time.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int m = a.size();
        int n = b.size();

        // Ensure a is smaller array for optimization
        if (m > n) {
            // Swap a and b
            return kthElement(b, a, k); 
        }
        
        // Length of the left half
        int left = k; 

        // Apply binary search
        int low = max(0, k - n), high = min(k, m);
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            // Initialize l1, l2, r1, r2
            int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < m) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < n) ? b[mid2] : INT_MAX;

            // Check if we have found the answer
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } 
            else if (l1 > r2) {
                // Eliminate the right half
                high = mid1 - 1;
            } 
            else {
                // Eliminate the left half
                low = mid1 + 1;
            }
        }
        
         // Dummy return statement 
        return -1;
    }
};

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    
    //Create an instance of Solution class
    Solution solution;
    
    //Print the answer
    cout << "The " << k << "-th element of two sorted arrays is: "
         << solution.kthElement(a, b, k) << '\n';

    return 0;
}
