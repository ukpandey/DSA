//Problem Statement: Given a non-empty array of integers arr, 
//every element appears twice except for one. Find that single one.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int linearSearch(vector<int> v){
    int n=v.size();
   
    for(int i=0; i<n; i++){
        int ans = v[i];
        int c=0;
        for(int j=0; j<n; j++){
            if(ans==v[j])
                c++;
        }
        if(c==1)
            return ans;
    }
    return -1;
}
int usingHashing(vector<int> v){
    int n=v.size();
    unordered_map<int,int> mp;
    for(auto it:v)
        mp[it]++;
    for(auto it:mp)
        if(it.second==1)
            return it.first;
    return -1;
}

int usingXor(vector<int> v){
    int Xor = 0;
    for(auto it:v)
        Xor = Xor^it;
    return Xor;
}
int main(){
    vector<int> v = {4, 1, 2, 1, 2,4,5};
    cout<<linearSearch(v)<<endl;
    cout<<usingHashing(v)<<endl;
    cout<<usingXor(v);
}