#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void useReverse(vector<int> &v, int d){
    int n = v.size();
    d = d%n;
    reverse(v.begin(), v.begin()+d);
    reverse(v.begin()+d, v.end());
    reverse(v.begin(), v.end());
}

void leftRotateByDPlace(vector<int> &v, int d){
    int n = v.size();
    int x = d%n;
    vector<int> temp(x);
    for(int i=0; i<x; i++){
        // cout<<v[i]<<endl;
        temp[i] = v[i];
    }
        

    for(int i = x; i<n; i++){
        v[i-x] = v[i];
    }
    int j=0;
    for(int i = n-x; i<n; i++){
        v[i] = temp[i-(n-x)];
    }
  
}
int main(){
    vector<int> v{1,2,3,4,5,6,7}; 
    cout<<"Enter D: ";
    int D;
    cin>>D;
    // leftRotateByDPlace(v,D);
    useReverse(v,D);
    for(auto it: v)
        cout<<it<<" ";
}