#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void nextPermutation(vector<int> &v){
    int n = v.size();
    int index = -1;
    for(int i = n-2; i>=0; i--){
        if(v[i]<v[i+1]){
            index = i;
            break;
        }
    }
    if(index==-1){
        reverse(v.begin(), v.end());
        return;
    }
    for(int i=n-1; i>index; i--){
        if(v[i]>v[index]){
            swap(v[i],v[index]);
            break;
        }
    }
    reverse(v.begin()+index+1, v.end());
}
int main(){
    vector<int> v{2,1,5,4,3,0,0};
    // in built function for next permuation
    // next_permutation(v.begin(),v.end());
    nextPermutation(v);
    for(auto it:v)
        cout<<it<<" ";
}