#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    vector<int> v{5,4,6,3,2,1};
    priority_queue<int> pq;
    int n = v.size();
    int k=4;
    for(int i=0; i<k; i++){
        pq.push(v[i]);
    }
    for(int i=k; i<n; i++){
        if(pq.top()>v[i]){
            pq.pop();
            pq.push(v[i]);
        }
            
    }
    cout<<pq.top();
}