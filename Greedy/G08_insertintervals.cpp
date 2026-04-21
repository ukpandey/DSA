#include<iostream>
#include<vector>
using namespace std;

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

vector<vector<int>> insertAndMerge(vector<vector<int>> intervals, vector<int> insert){
    vector<vector<int>> ans;
    int i=0;
    int n = intervals.size();

    // find out the left part 
    while(i<n && intervals[i][1] < insert[0]){
        ans.push_back(intervals[i]);
        i++;
    }

    // push and merge 
    while(i<n && intervals[i][0] <= insert[1]){
        insert[0] = min(insert[0], intervals[i][0]);
        insert[1] = max(insert[1], intervals[i][1]);
        i++;
    }
    ans.push_back(insert);

    // push the right
    while(i<n){
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}

int main(){
    vector<vector<int>> intervals = {{1,3},{4,5}, {6,7},{8,10}};
    vector<int> insert = {5,6};

    vector<vector<int>> ans = insertAndMerge(intervals,insert);

    for(auto interval:ans){
        for(auto it:interval)
            cout<<it<<" ";
        cout<<",";
    }
    return 0;
}