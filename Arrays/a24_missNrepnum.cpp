#include<iostream>
#include<vector>
using namespace std;
pair<int,int> optimal1(vector<int> v){
    long long  n = v.size();
    long long Sn = (n*(n+1))/2;
    long long S2n = (n*(n+1)*(2*n+1))/6;
    long long S=0, S2=0;
    for(auto it:v){
        S+=it;
        S2+=((long long)it* (long long)it);
    }
    long long val1 = S-Sn;
    long long val2 = S2-S2n;
    long long x = (val1 + (val2/val1))/2;
    long long y = x - val1;
    return {(int)x, (int)y};
}

int main(){
    vector<int> v{1,2,3,2};
    pair<int,int> ans = optimal1(v);
    cout<<ans.first<<" "<<ans.second;
}