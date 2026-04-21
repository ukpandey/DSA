#include<iostream>
#include<vector>
using namespace std;

int atMost(vector<int> nums, int k){
    int n = nums.size();
    int l=0, r=0;
    int ans = 0;
    int sum = 0;
    while(r<n){
        sum += nums[r];
        while(sum>k){
            sum = sum - nums[l];
            l++;
        }
        ans += r-l+1;
    }
    return ans;
}

int maxSubArrayWithSumK(vector<int> nums, int k){
    return atMost(nums,k) - atMost(nums,k-1);
}
int main(){
    return 0;
}