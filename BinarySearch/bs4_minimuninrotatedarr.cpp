#include<iostream>
#include<vector>
using namespace std;
int findMin(vector<int> v){
    int n = v.size();
    int ans = INT32_MAX;
    int low = 0; 
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        // check if array is right sorted
        if(v[low]<=v[mid]){
            ans = min(ans,v[low]);
            low = mid+1;
        }
        else{
            ans = min(ans, v[mid]);
            high = mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int> v{4,5,6,7,1,2,3};
    cout<<findMin(v);

}