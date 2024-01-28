#include<iostream>
#include<vector>
using namespace std;
int findSingleElement(vector<int> v){
    int n=v.size();
    if(n==1) return v[0];
    if(v[0]!=v[1]) return v[0];
    if(v[n-1]!=v[n-2]) return v[n-1];
    int low=1, high=n-2;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]!=v[mid-1] && v[mid]!=v[mid+1]) 
            return v[mid];
        // if i am standing in left side and element is 
        // present at right side
        else if((mid%2==0 && v[mid] == v[mid+1])||
                 mid%2==1 && v[mid] == v[mid-1]){
                    low = mid+1;
                 }
        // we are on right and want to go to left side
        else
            high = mid-1;
    }
    return -1;
}

int main(){
    vector<int> v{1,1,2,2,3,4,4,5,5,6,6};
    cout<<findSingleElement(v);
}