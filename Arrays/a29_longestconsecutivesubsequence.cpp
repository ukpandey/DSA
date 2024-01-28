#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

// O(nlogn) + O(n);
int better(vector<int> v){
    int n = v.size();
    sort(v.begin(), v.end());
    int lastSmaller = INT16_MIN;
    int cnt = 0, longest = 1;
    for(int i=0; i<n; i++){
        if(v[i] - 1 == lastSmaller){
            cnt+=1;
            lastSmaller = v[i];
        }
        else if(v[i]!=lastSmaller){
            cnt=1;
            lastSmaller=v[i];
        }
        longest = max(longest,cnt);
    }
    return longest;
}
// O(n)+ O(n+n)
int optimal(vector<int> v){
    unordered_set<int> st(v.begin(), v.end());
    int longest = 1;
    int count = 0;
    for(auto it:st){
        if(st.find(it-1) == st.end()){
            count = 1;
            int x = it;
            while(st.find(x+1)!=st.end()){
                x=x+1;
                count++;
            }
        }
        longest = max(longest,count);
    }
    return count;
}
int main(){
    vector<int> v{1,44,6,3,2,2,5,46,47,47,100,101,4};
    cout<<optimal(v)<<endl;
    cout<<better(v);
}