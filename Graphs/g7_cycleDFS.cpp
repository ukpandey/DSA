#include<iostream>
#include<vector>
using namespace std;

void createAdjacencyList(int edges, vector<int> adj[]){
    int u,v;
    for(int i=0; i<edges; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool dfs(int node, vector<int> &visited, vector<int> adj[], int parent){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            if(dfs(it,visited,adj,node))
                return true;
        }
        else if(parent!=it)
            return true;
    }
}

bool isCycleDFS(vector<int> adj[], int nodes){
    vector<int> visited(nodes+1,0);
    for(int i=1; i<=nodes; i++){
        if(!visited[i]){
            if(dfs(i,visited,adj,-1))
                return true;
        }
    }
    return false;
}

int main(){
    int nodes, edges;
    cout<<"Enter total number of nodes and edges: ";
    cin>>nodes>>edges;
    vector<int> adj[nodes+1];
    createAdjacencyList(edges,adj);

    if(isCycleDFS(adj,nodes))
        cout<<"Cycle is Present";
    else    
        cout<<"Cycle is not Present";
    return 0;
}