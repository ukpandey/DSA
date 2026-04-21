/*
Problem Statement: You are given an array 'arr' of size 'n' which denotes the 
position of stalls. You are also given an integer 'k' which denotes the number of
 aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance 
between any two of them is the maximum possible. Find the maximum possible minimum distance.

Examples
Example 1:
Input Format:
 N = 6, k = 4, arr[] = {0,3,4,7,10,9}
Result:
 3
Explanation:
The maximum possible minimum distance between any two cows will be 3 when 4 cows are 
placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 
respectively. We cannot make the minimum distance greater than 3 in any ways.

Example 2:
Input Format:
 N = 5, k = 2, arr[] = {4,2,1,3,6}
Result:
 5
Explanation:
 The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed 
 at positions {1, 6}. 
*/
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool canPlace(vector<int> stalls, int cows, int distance){
    int currentCows = 1;
    int lastPosition = stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i] - lastPosition >= distance){
            currentCows++;
            lastPosition = stalls[i];
        }
        if(currentCows >= cows){
            return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int> stalls, int cows){
    sort(stalls.begin(),stalls.end());
    int low = 1, high = stalls[stalls.size()-1];
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(canPlace(stalls,cows,mid)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    int cows = 4;
    vector<int> stalls = {0,3,4,7,10,9};
    cout<<aggressiveCows(stalls,cows);
    return 0;
}