// Problem Statement: Given an array of N integers, 
// write a program to return an element that occurs more than N/2 times in the given array. 
// You may consider that such an element always exists in the array.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int bruteForce(vector<int> v){
    int n = v.size();
    int count;
    for(int i=0; i<n; i++){
        count = 0;
        for(int j=0; j<n; j++){
            if(v[j] == v[i])
                count++;
        }
        if(count > (n/2))
            return v[i];
    }
    return -1;
}
int better(vector<int> v){
    int n = v.size();
    unordered_map<int,int> mp;

    for(auto it:v)
        mp[it]++;

    for(auto it:mp){
        if(it.second > (n/2))
            return it.first;
    }
    return -1;
}
// moore's voting algorithm
int optimal(vector<int> v){
    int n = v.size();
    int element = v[0];
    int count = 0;
    for(int i=0; i<n; i++){
        if(count == 0)
            element = v[i];
        if(v[i] == element)
            count++;
        else   
            count--;
    }
    count = 0;
    for(auto it:v){
        if(element == it)
            count++;
        if(count > (n/2))
            return element;
    }
    return -1;
}

int main(){
    vector<int> v = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    cout<<bruteForce(v)<<endl;
    cout<<better(v)<<endl;
    cout<<optimal(v)<<endl;
}