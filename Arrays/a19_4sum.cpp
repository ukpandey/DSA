#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> bruteForce(vector<int> v, int target){
    set<vector<int>> st;
    int n = v.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    if((v[i]+v[j]+v[k]+v[l]) == target){
                        vector<int> temp = {v[i],v[j],v[k],v[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>>  ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>> better(vector<int> v, int target){
    int n = v.size();
    set<vector<int>> ansSet;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set<int> st;
            for(int k=j+1; k<n; k++){
                int x = target - (v[i]+v[j]+v[k]);
                if(st.find(x)!=st.end()){
                    vector<int> temp{v[i],v[j],v[k],x};
                    sort(temp.begin(), temp.end());
                    ansSet.insert(temp);
                }
                st.insert(v[k]);
            }
        }
    }
    vector<vector<int>> ans(ansSet.begin(),ansSet.end());
    return ans;
}

vector<vector<int>> optimal(vector<int> v, int target){
    vector<vector<int>> ans;
    sort(v.begin(), v.end());
    int n = v.size();
    for(int i=0; i<n; i++){
        if(i>0 && v[i]==v[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j!=i+1 && v[j] == v[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                int sum = v[i]+v[j]+v[k]+v[l];
                if(sum==target){
                    ans.push_back({v[i], v[j], v[k], v[l]});
                    k++;
                    l--;

                    while(k<l && v[k]==v[k-1]) k++;
                    while(k<l && v[l]==v[l+1]) l--;
                }
                else if(sum>target){
                    l--;
                }
                else{
                    k++;
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> v{1,1,1,2,2,2,3,3,3,4,4,4,5,5};
    // vector<int> v{1,0,-1,-2,2,0};

    int target = 8;
    vector<vector<int>> ans = bruteForce(v,target);
    for(auto rows:ans){
        for(auto it:rows)
            cout<<it<<" ";
        cout<<endl;
    }
    cout<<endl;
    ans = better(v,target);
    for(auto rows:ans){
        for(auto it:rows)
            cout<<it<<" ";
        cout<<endl;
    }
    cout<<endl;
    ans = optimal(v,target);
    for(auto rows:ans){
        for(auto it:rows)
            cout<<it<<" ";
        cout<<endl;
    }
}