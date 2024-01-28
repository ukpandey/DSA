#include<iostream>
#include<vector>
using namespace std;

int secondLargest(vector<int> v){
    int n = v.size();
    int largest = v[0];
    int slargest = -1;
    for(int i=1; i<n; i++){
        if(v[i]>largest){
            slargest = largest;
            largest = v[i];
        }
        else if(v[i]<largest && v[i]>slargest){
            slargest = v[i];
        }
    }
    return slargest;
}
int main(){
    vector<int> v {5,1,3,4,2};
    int sLargest = secondLargest(v);
    cout<<"Slargest is: "<<secondLargest(v);
}