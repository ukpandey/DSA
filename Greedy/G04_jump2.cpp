// You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

int jump(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=0;
        int jumps = 0;
        while(r<n-1){
            int farthest = INT_MIN;
            for(int i=l;i<=r;i++){
                farthest = max(farthest, i+nums[i]);
            }
            if (farthest == r) {
                return -1; // meaning you couldn't reach out the ranges
            }
            l = r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }