#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> v, int x){
    int n=v.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]==x) return mid;
        // if array is left sorted
        else if(v[mid]>=v[low]){
            if(x>=v[low] && x<=v[mid])
                high = mid - 1;
            else  
                low = mid+1;
        }
        //if array is right sorted
        else{
            if(x<=mid && x>=v[high])
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return -1;
}

//the above approach will fail if we have duplicate elements 
// like this
// 3 3 1 3 3 3 3

bool search2(vector<int> v, int x){
    int n=v.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]==x) return true;
        else if(v[low]==v[mid] && v[mid]==v[high]){
            low++; high--;
            continue;
        }
        // if array is left sorted
        else if(v[mid]>=v[low]){
            if(x>=v[low] && x<=v[mid])
                high = mid - 1;
            else  
                low = mid+1;
        }
        //if array is right sorted
        else{
            if(x<=mid && x>=v[high])
                low = mid+1;
            else
                high = mid-1;
        }
    }
    return false;
}

int main(){
    vector<int> v{4,5,6,1,2,3};
    int n;
    cin>>n;
    cout<<search(v,n)<<endl;
    vector<int> v2{3,3,1,3,3,3,3};
    cout<<search2(v2,4);
}