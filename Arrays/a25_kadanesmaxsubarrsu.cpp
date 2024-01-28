#include<iostream>
#include<vector>
using namespace std;

void kadaneAlgo(vector<int> v){
    int n=v.size();
    int maxSum = INT32_MIN;
    int sum = 0;
    int ansStart, ansEnd;
    int start = 0;
    for(int i=0; i<n; i++){
        if(sum == 0) start = i;
        sum+=v[i];
        if(sum>maxSum){
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum<0) sum = 0;
    }
    cout<<"Max Subarray Sum is "<<maxSum;
    cout<<"\nSubarray is\n";
    for(int i=ansStart; i<=ansEnd; i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    vector<int> v{-2,-3,4,-1,-2,1,5,-3};
    kadaneAlgo(v);
}