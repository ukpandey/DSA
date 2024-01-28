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

void dfs(int i, vector<int> &ans, vector<int> &visited, vector<int> adj[]){
    ans.push_back(i);
    visited[i]=1;
    for(auto it: adj[i]){
        if(!visited[it]){
            dfs(it,ans,visited,adj);
        }
    }
}

vector<int> dfsTraversal(int nodes, int edges, vector<int> adj[]){
    vector<int> ans;
    vector<int> visited(nodes+1, 0);
    for(int i=1; i<=nodes; i++){
        if(!visited[i])
            dfs(i, ans, visited, adj);
    }
    return ans;
}
int main(){
    int nodes, edges;
    cout<<"Enter number of nodes and edges: ";
    cin>>nodes>>edges;
    vector<int> adj[nodes+1];
    createList(edges, adj);

    vector<int> dfsAns = dfsTraversal(nodes,edges,adj);
    for(auto it:dfsAns)
        cout<<it<<" ";

}