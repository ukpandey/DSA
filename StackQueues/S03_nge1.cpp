#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// hum stack mai sirf greater element hee store karenge
// agar stack mai element hai toh vo next greater hai
// agar usse greater element aarha hai iska matlab uske pichle vale
// sab ho chuke hai 

vector<int> nextGreaterElement(vector<int> nums){
    vector<int> ans(nums.size());
    stack<int> st;
    for(int i=nums.size()-1; i>=0; i--){

        while(!st.empty() && nums[i]>=st.top()){
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

vector<int> nextGreaterElement2(vector<int> nums){
    int n = nums.size();
    vector<int> ans(n, -1);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<i+n-1; j++){
            int index = j%n; // 7%5 = 2, 3%5 = 3
            if(nums[index]>nums[i]){
                ans[i] = nums[index];
                break;
            }
        }
    }
    return  ans;
}

vector<int> nextGreaterElement2Optimal(vector<int> nums){
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i=2*n-1; i>=0; i--){
        int curr = nums[i%n];
        while(!st.empty() && curr>=st.top()){
            st.pop();
        }
        if(i<n){
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
        }
        st.push(curr);
    }
    return  ans;
}

int main(){
    vector<int> nums = {5,7,1,2,6,0};
    vector<int> nge = nextGreaterElement2Optimal(nums);
    for(auto it:nge){
        cout<<it<<" ";
    }
}