#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> bruteForce(vector<int> v){
    int n=v.size();
    vector<vector<int>> ans;
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(v[i]+v[j]+v[k] == 0){
                    vector<int> temp = {v[i], v[j], v[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    for(auto it: st){
        ans.push_back(it);
    }
    return ans;
}

vector<vector<int>> better(vector<int> v){
    int n=v.size();
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        set<int> hashset;
        for(int j=i+1; j<n; j++){
            int k = -(v[i]+v[j]);
            if(hashset.find(k) != hashset.end()){
                vector<int> temp = {v[i], v[j], k};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(v[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> optimal(vector<int> v){
    int n = v.size();
    vector<vector<int>> ans;
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        int j = i+1;
        int k = n-1;
        if(i>0 && v[i]==v[i-1]) continue;
        while(j<k){
            int sum = v[i]+v[j]+v[k];
            if(sum>0){
                k--;
            }
            else if(sum<0){
                j++;
            }
            else{
                ans.push_back({v[i],v[j],v[k]});
                j++;
                k--;
                while(j<k && v[j]==v[j-1]) j++;
                while(j<k && v[k]==v[k+1]) k--;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> v{-1,0,1,2,-1,-4};
    vector<vector<int>> triplets = bruteForce(v);
    for(auto it:triplets){
        for(auto it2: it)
            cout<<it2<<" ";
        cout<<endl;
    }
    triplets= better(v);
    for(auto it:triplets){
        for(auto it2: it)
            cout<<it2<<" ";
        cout<<endl;
    }
    triplets= optimal(v);
    for(auto it:triplets){
        for(auto it2: it)
            cout<<it2<<" ";
        cout<<endl;
    }
}