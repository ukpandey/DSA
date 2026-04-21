#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

vector<int> maxMeetings(vector<int>& start, vector<int>& end){
    vector<vector<int>> meetings;
    for(int i=0;i<start.size();i++){
        meetings.push_back({end[i],start[i],i+1});
    }
    sort(meetings.begin(),meetings.end());

    vector<int> ans;
    int freetime = -1;

    for(auto meeting:meetings){
        int endTime = meeting[0];
        int startTime = meeting[1];
        int meetingId = meeting[2];

        if(startTime > freetime){
            ans.push_back(meetingId);
            freetime = endTime;
        }
    }
    return ans;
}

int main(){
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};
    vector<int> totalMeetings = maxMeetings(start,end);
    for(auto it:totalMeetings)
        cout<<it<<" ";
    return 0;
}