/*
Count number of nice subarrays

Problem Statement: Given an array nums and an integer k. 
An array is called nice if and only if it contains k odd numbers. 
Find the number of nice subarrays in the given array nums..

Examples

Input :nums = [1, 1, 2, 1, 1] , k = 3
Output :2
Explanation :The subarrays with three odd numbers are [1, 1, 2, 1] [1, 2, 1, 1]
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

    int numberOfSubarrays(vector<int>& nums, int k) {

        // Frequency map to track how often a certain odd count has occurred
        unordered_map<int, int> freq;

        // Initialize with 0 count of odd numbers seen so far
        freq[0] = 1;

        // Running count of odd numbers in the current prefix
        int oddCount = 0;

        // Total number of nice subarrays
        int result = 0;

        // Traverse through each element in the array
        for (int num : nums) {

            // Check if current number is odd and update count
            if (num % 2 == 1) oddCount++;

            // If there exists a prefix with (current odd count - k), add its frequency to result
            if (freq.count(oddCount - k)) {
                result += freq[oddCount - k];
            }

            // Update the frequency of current odd count
            freq[oddCount]++;
        }

        // Return the total number of valid subarrays
        return result;
    }

int countAtMost(vector<int> nums, int k){
    int n = nums.size();
    int l=0, r=0;
    int ans = 0;
    int count = 0;
    while(r<n){
        if(nums[r]%2==1){
            k--;
        }
        while(k<0){
            if(nums[l]%2==1){
                k++;
            } 
            l++;
        }
        ans += r-l+1;
        r++;
    }
    return ans;
}

int countNiceSubarray(vector<int> nums, int k){
    return countAtMost(nums,k) - countAtMost(nums, k-1);
}

int main(){
    return 0;
}