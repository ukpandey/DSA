class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;

            if (nums[idx] < 0) {
                ans.push_back(idx + 1); // duplicate found
            } else {
                nums[idx] = -nums[idx]; // mark visited
            }
        }

        return ans;
    }
};
// Given an integer array nums of length n where all the integers of nums
//  are in the range [1, n] and each integer appears at most twice, 
//  return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant
//  auxiliary space, excluding the space needed to store the output

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]

// ⚡ Example Walkthrough

// nums = [4,3,2,7,8,2,3,1]

// Step	Num	Index	Action
// 0	4	3	mark nums[3] negative
// 1	3	2	mark nums[2] negative
// 2	2	1	mark nums[1] negative
// 3	7	6	mark nums[6] negative
// 4	8	7	mark nums[7] negative
// 5	2	1	already negative → duplicate = 2
// 6	3	2	already negative → duplicate = 3

// 👉 Output: [2, 3]