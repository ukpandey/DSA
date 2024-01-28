#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void createAdjacencyList(int edges, vector<int> adj[]){
    for(int i=0; i<edges; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool isCycleBFS(int src,vector<int> &visited, vector<int> adj[]){
    visited[src] = 1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it: adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push({it,node});
            }
            else if(it!=parent){
                return true;

            }
        }
    }
    return false;

}

int main(){
    int nodes, edges;
    cout<<"Enter total number of nodes and edges: ";
    cin>>nodes>>edges;
    vector<int> adj[nodes+1];
    createAdjacencyList(edges, adj);
    bool ans;
    vector<int> visited(nodes+1,0);
    for(int i=1; i<=nodes; i++){
        if(!visited[i]){
            ans=isCycleBFS(i,visited,adj);
            if(ans){
                 cout<<"Cycle is Present";
                 break;
            }
               
        }
    }
    if(!ans)
    cout<<"No cycle";
    return 0;
}