// Example 1:
// Input Format: N = 4, a[] = {7, 15, 6, 3}, h = 8
// Result: 5
// Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour 
// to eat the piles accordingly. So, he will take 8 hours to complete all the piles.  

// Example 2:
// Input Format: N = 5, a[] = {25, 12, 8, 14, 19}, h = 5
// Result: 25
// Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour 
// to eat the piles accordingly. So, he will take 5 hours to complete all the piles.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int bruteForce(vector<int> v, int h){
    int ans ;
    int max = *max_element(v.begin(),v.end());
    cout<<max<<endl;
    for(int i=1; i<=max; i++){
        ans = 0;
        for(auto it:v){
            ans = ans + ceil((double) (it) / (double) (i));
            cout<<ans<<" ";
        }
        cout<<endl;
        if(ans<=h) return i;
    }
    return max;
}

int optimal(vector<int> v, int h){
    int low = 0, high = *max_element(v.begin(),v.end());
    int ans = INT32_MAX;
    while(low<=high){
        int mid = low + (high-low)/2;
        int time = 0;
        for(auto it:v){
            time = time + ceil((double) (it) / (double) (mid));
        }
        if(time<=h){
            ans = min(ans,mid);
            high = mid-1;
        }
        else{
            low = mid+1;
        }

    }
    return ans; //return low can also be done here kyuki isme answer 
    // high = mid-1 mai nikalrhe hai
    
}
int main(){
    vector<int> v{7,15,6,3};
    int h = 7;
    // cout<<bruteForce(v,h);
    cout<<optimal(v,h);

}