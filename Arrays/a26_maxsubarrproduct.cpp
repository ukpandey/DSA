#include<iostream>
#include<vector>
using namespace std;
int optimal(vector<int> v){
    int n=v.size();
    int ans = INT32_MIN;
    int prefix = 1, suffix = 1;
    for(int i=0; i<n; i++){
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;
        prefix = prefix * v[i];
        suffix = suffix * v[n-i-1];
        ans = max(ans, max(prefix,suffix));
    }
    return ans;
}
int main(){
    vector<int> v{2,3,0,-2,-2,4};
    cout<<optimal(v);
}