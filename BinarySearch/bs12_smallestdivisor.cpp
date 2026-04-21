#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int smallestDivisor(vector<int> v, int threshold){
    int max = *max_element(v.begin(), v.end());
    int low = 0, high = max;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int count = 0;
        for(int i=0;i<v.size();i++){
            count += ceil((double) v[i] / (double) mid);
        }
        if(count<=threshold){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> v = {1,2,5,9};
    int threshold = 6;
    cout<<smallestDivisor(v,threshold);
    return 0;
}