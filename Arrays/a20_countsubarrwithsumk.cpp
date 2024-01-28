#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int bruteForce(vector<int> v,int k){
    int n = v.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        int sum = 0; 
        for(int j=i; j<n; j++){
            sum+=v[j];
            if(sum==k)
                ans++;
        }
    }
    return ans;
}

int prefixSum(vector<int> v, int k){
    int n= v.size();
    unordered_map<int,int> mp;
    mp[0] = 1;
    int presum = 0;
    int count = 0;
    for(int i=0; i<n; i++){
        presum+=v[i];
        count+=mp[presum-k];
        mp[presum]++;
    }
    return count;
}

int main(){
    vector<int> v{1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    cout<<bruteForce(v,k)<<endl;
    cout<<prefixSum(v,k);
}