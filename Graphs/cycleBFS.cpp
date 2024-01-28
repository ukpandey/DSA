#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void createAdjacencyList(int nodes, int edges, vector<int> adj[]){
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
}
bool isCycle(int node, vector<int> adj[], vector<int> &parent, vector<bool> &visited){
    queue<int> q;
    q.push(node);
    parent[node]=-1;
    visited[node]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v: adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v]=1;
                parent[v]=u;
            }
            else if(visited[v]&& parent[u]!=v)
                return true;
        }
    }
    return false;

}
int main(){
    cout<<"Enter number of nodes: ";
    int n;
    cin>>n;
    cout<<"Enter the edges: ";
    int m;
    cin>>m;
    vector<int> adj[n+1];
    createAdjacencyList(n,m,adj);
    vector<int> parent(n+1,-1);
    vector<bool> visited(n+1,false);
    bool ans;
    for(int i=1;i<=n;i++){
        if(!visited[i]){ans=isCycle(i,adj,parent,visited);
         if(ans){cout<<"Cycle is Present"; break;}}
        
            
    }
    if(!ans)
        cout<<"Cycle is not present";


}