#include<iostream>
#include<vector>
using namespace std;

void leftRotateBy1Place(vector<int> &v){
    int n = v.size();
    int temp = v[0];
    for(int i = 1; i<n; i++)
        v[i-1] = v[i];
    v[n-1] = temp;
}
int main(){
    vector<int> v{1,2,3,4,5,6,7}; 
    // ans 2 3 4 5 6 7 1
    leftRotateBy1Place(v);
    for(auto it: v)
        cout<<it<<" ";
}