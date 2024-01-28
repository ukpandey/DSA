#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

pair<int,int> bruteForce(vector<int> v, int target){
    int n=v.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(v[i]+v[j] == target){
                cout<<"Elements are "<<v[i]<<", "<<v[j]<<endl;
                return {i, j};
            }
        }
    }
    return {-1,-1};
}

pair<int,int> usingHashing(vector<int> v, int target){
    unordered_map<int,int> mp;
    int n= v.size();
    for(int i=0; i<n; i++){
        int x = target-v[i];
        if(mp.find(x) != mp.end()){
            cout<<"Elements are "<<x<<", "<<v[i]<<endl;
            return {mp[x],i};
        }
        mp[v[i]] = i;
    }
    return {-1,-1};
}

// do this if you have to return elements only

pair<int,int> usingSort(vector<int> v, int target){
    sort(v.begin(), v.end());
    int n=v.size();
    int left = 0, right = n-1;
    while(left<right){
        if(v[left]+v[right]==target){
            return {v[left],v[right]};
        }
        else if(v[left]+v[right]>target)
            right--;
        else 
            left++;
    }
    return {-1,-1};
}
int main(){
    vector<int> v{2,6,5,8,11};
    int target = 14;
    pair<int,int> ans = bruteForce(v,target);
    cout<<ans.first<<" "<<ans.second<<endl;;

    ans = usingHashing(v,target);
    cout<<ans.first<<" "<<ans.second<<endl;

    ans = usingSort(v,target);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}