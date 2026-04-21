// Problem Statement: Given an array of N intervals in the form of (start[i], end[i]), 
// where start[i] is the starting point of the interval and end[i] is the ending point
//  of the interval, return the minimum number of intervals that need to be removed to 
//  make the remaining intervals non-overlapping. .

// same question as n meetings

#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    // Function to find the minimum number of intervals to remove to make all intervals non-overlapping
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals based on their end time (greedy strategy)
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        // Count of intervals to remove
        int count = 0;

        // Store end time of the last non-overlapping interval
        int prevEnd = intervals[0][1];

        // Iterate through intervals starting from the second
        for (int i = 1; i < intervals.size(); i++) {

            // If current interval starts before the last accepted interval ends
            if (intervals[i][0] < prevEnd) {
                // Overlapping interval, increase removal count
                count++;
            } else {
                // No overlap, update the end of last accepted interval
                prevEnd = intervals[i][1];
            }
        }

        // Return minimum intervals to remove
        return count;
    }
};
// Driver Code
int main() {
    Solution sol;

    // Example input intervals
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {3, 5}, {1, 2}};

    // Call the function and print result
    cout << "Minimum number of intervals to remove: " << sol.eraseOverlapIntervals(intervals) << endl;
    return 0;
}