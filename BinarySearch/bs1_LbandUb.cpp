#include<iostream>
#include<vector>
using namespace std;

// lowest index such that v[i]>=x
int lowerBound(vector<int> v, int x){
    int n=v.size();
    int ans = n;
    int low = 0, high = n-1 ;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]>=x){
            // ans = min(ans,mid);
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int> v, int x){
    int n=v.size();
    int ans = n;
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(v[mid]>x){
            ans = mid;
            high = mid-1;
        }
        else if(v[mid]<=x){
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> v{1,1,2,3,5,7,7,7,8};
    cout<<"Enter the element: ";
    int x;
    cin>>x;
    cout<<lowerBound(v,x)<<endl;
    cout<<(lower_bound(v.begin(), v.end(), 1) - v.begin())<<endl;
    cout<<upperBound(v,x)<<endl;
    cout<<(*lower_bound(v.begin(), v.end(), 1))+1<<endl;

}