#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minDays(vector<int>& bloomDay, int m, int k) {
    int low = *min_element(bloomDay.begin(),bloomDay.end());
    int high = *max_element(bloomDay.begin(),bloomDay.end());
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int flowers = 0;
        int bouqets = 0;
        for(auto it:bloomDay){
            if(it<=mid){
                flowers++;
            }
            if(flowers == k){
                bouqets++;
                flowers = 0;
            }
            if(it>mid){
                flowers = 0;
            }
        }
        if(bouqets >= m){
            high = mid-1;
            ans = mid;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> bloomDays = {7,7,7,7,13,11,12,7};
    int bouqets = 2, adjacentFlowers = 3;
    cout<<"Minimum days to make bouquets: "<<minDays(bloomDays, bouqets, adjacentFlowers);
}