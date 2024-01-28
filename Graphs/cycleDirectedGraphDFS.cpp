#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void createAdjacencyList(int nodes, int edges, vector<int> adj[])
{
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
       // adj[v].push_back(u);
    }
}
bool isCycleDFS(int node,vector<int> &visited, vector<int> &dfsVisited, vector<int> adj[]){
    visited[node]=1;
    dfsVisited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            if(isCycleDFS(it,visited,dfsVisited,adj))
                return true;
        }
        else if(dfsVisited[it])
            return true;
    }
    dfsVisited[node]=0;
    return false;
}
bool isCycle(int n, vector<int> &visited, vector<int>& dfsVisited,vector<int> adj[]){
    for(int i=1;i<=n;i++){
        if(!visited[i] && isCycleDFS(i,visited,dfsVisited,adj))
            return true;
    }
    return false;
}
int main()
{
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;
    cout << "Enter the edges: ";
    int m;
    cin >> m;
    vector<int> adj[n+1];
    createAdjacencyList(n,m,adj);
    vector<int> visited(n+1,0);
    vector<int> dfdsVisited(n+1,0);
    if(isCycle(n,visited,dfdsVisited,adj))
        cout<<"Cycle is present";
    else
        cout<<"Cycle is not present";

}
