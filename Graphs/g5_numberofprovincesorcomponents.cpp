// This program is for number of components or provinces in a graph
#include<iostream>
#include<vector>
using namespace std;

void createList(int edges, vector<int> adj[]){
    int u,v;
    for(int i=0; i<edges; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfsTraversal(int i, vector<int> &visited, vector<int> adj[]){
    visited[i]=1;
    for(auto it: adj[i]){
        if(!visited[it])
            dfsTraversal(it,visited,adj);
    }
}
int main(){
    int nodes, edges;
    cout<<"Enter total number of nodes and edges: ";
    cin>>nodes>>edges;
    vector<int> adj[nodes+1];
    createList(edges,adj);
    int count = 0;
    vector<int> visited(nodes+1,0);
    for(int i=1; i<=nodes; i++){
        if(!visited[i]){
            count++;
            dfsTraversal(i,visited,adj);
        }
    }

    cout<<"Total number of provinces: "<<count;
    return 0;
}
    