#include<iostream>
#include<vector>
using namespace std;

int longestOnes2(vector<int> nums, int k){
    int n = nums.size();
    int l=0,r=0,ans=0,zeroes=0;
    while(r<n){
        if(nums[r]==0){
            zeroes++;
        }
        while(zeroes>k){
            if(nums[l]==0){
                zeroes--;
            }
            l++;
        }
        ans = max(r-l+1, ans);
        r++;
    }
    return ans;
}
int longestOnes3(vector<int> nums, int k){
    int n=nums.size();
    int l=0, r=0;
    int ans = 0;
    int zeroes =0;
    while(r<n){
        if(nums[r]==0){
            zeroes++;
        }
        if(zeroes>k){
            if(nums[l]==0){
                zeroes--;
            }
            l++;
        }
        ans = max(r-l+1, ans);
        r++;
    }
    return ans;
}


int main(){

    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int ans = longestOnes2(nums,k);
    cout<<"Max consecutive ones after flipping k zeroes: "<<ans;
    return 0;
}