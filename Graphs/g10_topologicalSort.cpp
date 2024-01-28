#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void topoSortDFS(int node, vector<int> adj[], vector<int> &visited, stack<int>&s){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            topoSortDFS(it,adj,visited,s);
        }
    }
    s.push(node);
}
void topoSort(int n, vector<int> adj[], vector<int> &visited,stack<int> &s){
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            topoSortDFS(i,adj,visited,s);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> visited(n+1,0);
    stack<int> s;
    topoSort(n,adj,visited,s);
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    
    return 0;
}