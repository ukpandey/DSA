#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int bruteForce(vector<int> v,int k){
    int n = v.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        int Xor = 0; 
        for(int j=i; j<n; j++){
            Xor = Xor^v[j];
            if(Xor==k)
                ans++;
        }
    }
    return ans;
}

int prefixSum(vector<int> v, int k){
    int n= v.size();
    unordered_map<int,int> mp;
    mp[0] = 1;
    int preXor = 0;
    int count = 0;
    for(int i=0; i<n; i++){
        preXor = preXor^v[i];
        count+=mp[preXor^k];
        mp[preXor]++;
    }
    return count;
}

int main(){
    vector<int> v{4,2,2,6,4};
    int k = 6;
    cout<<bruteForce(v,k)<<endl;
    cout<<prefixSum(v,k);
}