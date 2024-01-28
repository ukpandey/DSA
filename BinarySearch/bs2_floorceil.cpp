#include<iostream>
#include<vector>
using namespace std;

int floor(vector<int> v, int x){
    int n = v.size(), ans = -1, low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]<=x){
            ans = v[mid];
            low = mid + 1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int ceil(vector<int> v, int x){
    int n=v.size(), ans = -1, low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]>=x){
            ans = v[mid];
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> v{10,20,30,40,50};
    cout<<"Floor: "<<floor(v,25)<<endl; // simple lower bound but >= ki jagah <=
    cout<<"Ceil: "<<ceil(v,25); // simple lower bound 
}