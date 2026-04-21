#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 

// railway station jao, or dekho ki kon si train kitne baje aarhi hai.
// agar 1 train khadi hai railway station pe or vo abhi tak gyi nhi hai
// or issi beech 1 or train aagyi toh usko train ko dusre platform pe jaana hoga
// agar dusri train k aane se pehle koi train chaligyi toh 1 plaform khali hogyya

int findMinPlatforms(vector<int> &arrival, vector<int> &departure){
    int n = arrival.size();
    int i=0, j=0;
    int maxCount = 0, count = 0;
    sort(arrival.begin(),arrival.end());
    sort(departure.begin(),departure.end());
    while(i<n){
        if(arrival[i]<=departure[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        maxCount = max(maxCount,count);
    }
    return count;
}
int main(){
    vector<int> arrival = {900,945,955,1100,1500,1800};
    vector<int> departure = {920,1130,1150,1200,1900,2000};
    int minimumPlatforms = findMinPlatforms(arrival,departure);
    string s;
    s.length();
    return 0;
}