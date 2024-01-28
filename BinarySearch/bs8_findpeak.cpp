#include<iostream>
#include<vector>
using namespace std;
int findPeak(vector<int> v){
    int n=v.size();
    if(n==1) return 0;
    if(v[0]>v[1]) return 0;
    if(v[n-1]>v[n-2]) return n-1; 
    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]>v[mid+1] && v[mid]>v[mid-1]){
            return mid;
        }
        else if(v[mid]>v[mid-1]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> v{1,2,3,5,3,2,1};
    cout<<findPeak(v)<<endl;
}