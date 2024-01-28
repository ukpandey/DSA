#include<iostream>
using namespace std;
int findSqrt(int n){
    int low = 1, high = n;
    int ans;
    while(low<=high){
        int mid = low +(high-low)/2;
        if(mid*mid <= n){
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }
    return ans ; // return high can also be done  
    //note: bhai agar low = mid+1 mai index nikal rhe ho toh high return kar skte 
    // hai and vice versa // refer to bs10
}
int main(){
    int n;
    cin>>n;
    cout<<findSqrt(n);
}