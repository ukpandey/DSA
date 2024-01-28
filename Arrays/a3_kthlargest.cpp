#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    vector<int> v{4,7,2,3,5};
    int n = v.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    int k=3;
    for(int i=0; i<k; i++){
        pq.push(v[i]);
    }
    for(int i=k; i<n; i++){
        if(v[i]>pq.top()){
            pq.pop();
            pq.push(v[i]);
        }
    }
    cout<<pq.top();
}