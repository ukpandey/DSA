#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void createList(int edges, vector<int> adj[])
{
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool bfs(int start, vector<int> &colors, vector<int> adj[]){
    colors[start]=0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adj[node]){
            if(colors[it]==-1){
                colors[it] = !colors[node];
                q.push(it);
            }
            else if(colors[it]==colors[node]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int nodes, vector<int> adj[]){
    vector<int> colors(nodes+1, -1);
    for(int i=1; i<=nodes; i++){
        if(colors[i]==-1){
            if(!bfs(i,colors,adj))
                return false;
        }
    }
    return true;
}

int main(){
    int nodes, edges;
    cout << "Enter total number of nodes and edges: ";
    cin >> nodes >> edges;
    vector<int> adj[nodes + 1];
    createList(edges, adj);
    if(isBipartite(nodes,adj))
        cout<<"This Graph is BiPartite";
    else    
        cout<<"This graph is not BiPartite";
}