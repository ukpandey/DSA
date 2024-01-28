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
bool dfs(int start, vector<int> &colors, int color, vector<int> adj[]){
    colors[start]=color;
    for(auto it:adj[start]){
        if(colors[it]==-1){
           if(!dfs(it,colors,!color,adj))
            return false;
        }
        else if(colors[it]==color){
            return false;
        }
    }
    return true;

}
bool isBipartite(int nodes, vector<int> adj[]){
    vector<int> colors(nodes+1, -1);
    for(int i=1; i<=nodes; i++){
        if(colors[i]==-1){
            if(!dfs(i,colors,0, adj))
                return false;
        }
    }
    return true;
}
int main(){
    int nodes, edges;
    cout<<"Enter number of nodes and edges: ";
    cin>>nodes>>edges;
    vector<int> adj[nodes+1];
    createList(edges, adj);
        if(isBipartite(nodes,adj))
        cout<<"This Graph is BiPartite";
    else    
        cout<<"This graph is not BiPartite";

    return 0;
}

