#include<iostream>
#include<vector>
using namespace std;

int waterAccumalated(vector<int> buildings){
    int n = buildings.size();
    vector<int> prefixMax(n);
    vector<int> suffixMax(n);

    prefixMax[0]=buildings[0];
    for(int i=1; i<n; i++){
        prefixMax[i] = max(prefixMax[i-1], buildings[i]);
    }

    suffixMax[n-1]=buildings[n-1];
    for(int i=n-2;i>=0;i--){
        suffixMax[i] = max(suffixMax[i+1], buildings[i]);
    }


    int totalWater = 0;
    for(int i=0; i<n; i++){
        if(buildings[i]<prefixMax[i] && buildings[i]<suffixMax[i]){
            totalWater += min(prefixMax[i],suffixMax[i]) - buildings[i];
        } 
    }

    return totalWater;
}

int main(){
    vector<int> buildings = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<waterAccumalated(buildings);
    return 0;
}