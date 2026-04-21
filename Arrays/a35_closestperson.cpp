// Maximize Distance to Closest Person You are given an array representing a 
// row of seats where seats[i] = 1 represents a person sitting in the ith seat,
//  and seats[i] = 0 represents that the ith seat is empty (0-indexed). 
//  There is at least one empty seat, and at least one person sitting.
//   Alex wants to sit in the seat such that the distance between him and the
//    closest person to him is maximized. Return that maximum distance to the 
//    closest person. Input: seats = [1,0,0,0,1,0,1] Output: 2 Explanation: 
//    If Alex sits in the second open seat (i.e. seats[2]), then the closest
//     person has distance 2. If Alex sits in any other open seat, 
//     the closest person has distance 1. Thus, the maximum distance to 
//     the closest person is 2.
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int last = -1;  // last occupied seat
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (last == -1) {
                    // leading zeros
                    ans = i;
                } else {
                    // middle zeros
                    ans = max(ans, (i - last) / 2);
                }
                last = i;
            }
        }

        // trailing zeros
        ans = max(ans, n - 1 - last);

        return ans;
    }
};