#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void dfs(vector<int> adj[],int &timer,int node, vector<int> &visited, vector<int> &disc,vector<int> &low,int &parent,vector<vector<int>> &result ){
    visited[node]=1;
    disc[node]=low[node]=timer++;
    for(auto nbr:adj[node]){
        if(nbr==parent)
            continue;
        if(!visited[nbr]){
            dfs(adj,timer,nbr,visited,disc,low,node,result);
            low[node]=min(low[node],low[nbr]);
            // check bridge
            if(low[nbr]>disc[node]){
                cout<<node<<" "<<nbr<<endl;
            }
        }
        else{ //backedge case
                low[node]=min(low[node],disc[nbr]);
        }
    }

}
void bridge(vector<int> adj[],int n){
    int timer=0;
    vector<vector<int>> result;
    vector<int> visited(n+1,0);
    vector<int> disc(n+1,-1);
    vector<int> low(n+1,-1);
    int parent=-1;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(adj,timer,i,visited,disc,low,parent,result);
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
        adj[v].push_back(u);
    }
    bridge(adj,n);
    
    return 0;
}