#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

    vector<int> v {21,15, 6, 2, 1, 16, 4, 2, 29, 9, 12, 8, 5, 14, 21, 8, 12, 17, 16, 6, 26, 3 };
    sort(v.begin(), v.end());
    for(auto it:v)
        cout<<it<<" ";
}