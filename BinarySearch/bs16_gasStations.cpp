/*
Problem Statement: You are given a sorted array ‘arr’ of length ‘n’, which contains positive
integer positions of ‘n’ gas stations on the X-axis. 
You are also given an integer ‘k’. You have to place 'k' new gas stations on the X-axis. 
You can place them anywhere on the non-negative side of the X-axis, even on non-integer
positions. Let 'dist' be the maximum value of the distance between adjacent gas
stations after adding k new gas stations. Find the minimum value of ‘dist’.

Examples
Example 1:
Input Format: N = 5, arr[] = {1,2,3,4,5}, k = 4
Result: 0.5
Explanation: One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}.
Thus the maximum difference between adjacent gas stations is 0.5.
Hence, the value of ‘dist’ is 0.5. It can be shown that there is no possible way to add 4 
gas stations in such a way that the value of ‘dist’ is lower than this. 

Example 2:
Input Format: N = 10, arr[] = {1,2,3,4,5,6,7,8,9,10}, k = 1
Result: 1
Explanation: One of the possible ways to place 1 gas station is {1,1.5,2,3,4,5,6,7,8,9,10}. 
Thus the maximum difference between adjacent gas stations is still 1. 
Hence, the value of ‘dist’ is 1. It can be shown that there is no possible way to add 1 gas 
station in such a way that the value of ‘dist’ is lower than this.
*/

#include<iostream>
#include<vector>
#include <queue>
using namespace std;

long double minimizeMaxDistanceBrute(vector<int> v, int k){
    int n = v.size();
    vector<int> sections(n-1,0);
    for(int gasStations=0; gasStations<k; gasStations++){
        int maxIndex = -1;
        long double maxSection = -1;
        for(int j=0;j<n-1;j++){
            long double diff = v[j+1]-v[j];
            long double sectionLength = diff / (long double) (sections[j]+1);
            if(sectionLength>maxSection){
                maxIndex = j;
                maxSection = sectionLength;
            }
        }
        sections[maxIndex]++;
    }
    long double ans = -1;
    for(int i=0;i<n-1;i++){
        long double diff = v[i+1]-v[i];
        long double sectionLength = diff / (long double) (sections[i]+1);
        ans = max(ans,sectionLength);
    }
    return ans;
}

long double minimizeMaxDistanceHeap(vector<int> v, int k){
    int n = v.size();
    vector<int> sections(n-1,0);
    priority_queue<pair<long,int>> pq;
    for(int i=0; i<n-1; i++){
        pq.push({v[i+1]-v[i],i});
    }
    for(int gasStations=0; gasStations<k; gasStations++){
        auto top = pq.top();
        pq.pop();
        int sectionIndex = top.second;
        sections[sectionIndex]++;
        long double initialDiff = v[sectionIndex+1] - v[sectionIndex];
        long double newDiff = initialDiff / (long double)(sections[sectionIndex]+1);
        pq.push({newDiff,sectionIndex});
    }
    return pq.top().first;
}

    // Function to calculate number of gas stations required such that
    // no segment exceeds the max allowed distance `dist`
    int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
        int n = arr.size();
        int cnt = 0;

        for (int i = 1; i < n; i++) {
            // Number of stations needed between arr[i-1] and arr[i]
            int numberInBetween = (arr[i] - arr[i - 1]) / dist;

            // If perfectly divisible, reduce one to avoid extra placement
            if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
                numberInBetween--;
            }
            cnt += numberInBetween;
        }
        return cnt;
    }

    // Function to minimize the maximum distance between gas stations
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        long double low = 0, high = 0;

        // Determine max initial distance between stations
        for (int i = 0; i < n - 1; i++) {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }

        long double diff = 1e-6;

        // Binary search to find minimum possible maximum distance
        while (high - low > diff) {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, arr);
            if (cnt > k) low = mid;
            else high = mid;
        }

        return high;
    }

int main(){
    vector<int> v = {1,13,17,23};
    int k = 5;
    cout<<minimizeMaxDistanceHeap(v,k);
    return 0;
}