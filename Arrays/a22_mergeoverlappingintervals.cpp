#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// O(nlogn) + O(2n)
vector<vector<int>> bruteFoce(vector<vector<int>> v){
    vector<vector<int>> ans;
    int n = v.size();
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        int start = v[i][0];
        int end = v[i][1];
        if(!ans.empty() && end<=ans.back()[1]){continue;}
        for(int j=i+1; j<n; j++){
            if(v[j][0] <= end){
                end = max(end, v[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}

// O(nlogn) + O(n)
vector<vector<int>> optimal(vector<vector<int>> v){
    int n=v.size();
    vector<vector<int>> ans;
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        if(ans.empty() || ans.back()[1] < v[i][0] )
            ans.push_back(v[i]);
        else
            ans.back()[1] = max(ans.back()[1], v[i][1]);
    }
    return ans;
}
int main(){
    vector<vector<int>> v{{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
    vector<vector<int>> ans = bruteFoce(v);
    for(auto rows: ans){
        for(auto it:rows)
            cout<<it<<" ";
        cout<<endl;
    }
    cout<<"\n\n";
    ans = optimal(v);
    for(auto rows: ans){
        for(auto it:rows)
            cout<<it<<" ";
        cout<<endl;
    }
}