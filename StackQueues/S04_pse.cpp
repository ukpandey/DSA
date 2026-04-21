#include<iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int> prevSmallerElement(vector<int> nums){
    vector<int> ans(nums.size());
    stack<int> st;
    for(int i=0; i<nums.size(); i++){

        while(!st.empty() && nums[i]<=st.top()){
            st.pop();
        }

        if(st.empty()){
            ans[i]=-1;
        }
        else {
            ans[i] = st.top();
        }
        
        st.push(nums[i]);
    }
    return ans;
}



vector<int> prevSmallerElement2(vector<int> nums){
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i=0; i<2*n; i++){
        int curr = nums[i%n];
        while(!st.empty() && curr<=st.top()){
            st.pop();
        }
        if(i>n-1){
            if(st.empty()){
                ans[i%n] = -1;
            }
            else{
                ans[i%n] = st.top();
            }
        }
        st.push(curr);
    }
    return  ans;
}

int main(){
    vector<int> nums = {5,7,9,6,7,4,5,1,3,7};
    vector<int> nge = prevSmallerElement2(nums);
    for(auto it:nge){
        cout<<it<<" ";
    }
}