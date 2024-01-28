#include<iostream>
#include<vector>
using namespace std;

int secondSmallest(vector<int> v){
    int n = v.size();
    int smallest = v[0];
    int ssmallest = INT32_MAX;
    for(int i=1; i<n; i++){
        if(v[i]<smallest){
            ssmallest = smallest;
            smallest = v[i];
        }
        else if(v[i]>smallest && v[i]<ssmallest){
            ssmallest = v[i];
        }
    }
    return ssmallest;
}
int main(){
    vector<int> v {5,1,3,4,2,1,2};
    cout<<"Slargest is: "<<secondSmallest(v);
}