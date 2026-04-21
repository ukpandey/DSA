#include<iostream>
#include<vector>
#include<deque>
using namespace std;

/*
We use a deque to maintain the k elements and find maximums easily.

When we find an element in the array greater than the top element, 
we remove lower elements from the deque since the max is changing.

We continue this until we find a bigger element in the deque than the current 
element in the array.

When i > k - 1, we add the answer because our window is at least k elements wide.

We also maintain the correct size by checking i - k <= dq.front() to ensure 
we only have elements from the current subarray.

The elements are stored in decreasing order from bottom to top, 
so dq.front() always gives the current maximum for the subarray.
*/

vector<int> maxWindowSliding(vector<int> nums, int k){
    vector<int> ans;
    deque<int> dq;
    int n = nums.size();
    for(int i=0; i<n; i++){
          
        // maintain window size k
        if(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }

        // we have to store max on the front always
        while(!dq.empty() && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);

        // if the current window has been ended or new window has started
        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {4,0,-1,3,5,6,8};

    for(auto it: maxWindowSliding(nums,3)){
        cout<<it<<" ";
    }
    return 0;
}