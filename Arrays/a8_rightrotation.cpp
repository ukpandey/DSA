#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void useReverse(vector<int> &v, int d){
    int n = v.size();
    d = d%n;
    reverse(v.begin(), v.begin()+d+1);
    reverse(v.begin()+d+1, v.end());
    reverse(v.begin(), v.end());
}

int main(){
    vector<int> v{1,2,3,4,5,6,7};
    cout<<"Enter D: ";
    int d;
    cin>>d;
    useReverse(v,d);
    for(auto it:v)
        cout<<it<<" ";
}