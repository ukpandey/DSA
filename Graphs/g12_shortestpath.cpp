#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void createAdjList(int edges, vector<pair<int,int>> adj[]){
    for(int i=0; i<edges; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

}

void topoSort(int node, stack<int> &s, vector<pair<int,int>> adj[], vector<int> &visisted){
    visisted[node]=1;
    for(auto it: adj[node]){
        if(!visisted[it.first])
            topoSort(it.first, s,adj,visisted);
    }
    s.push(node);
}

vector<int> shortestPath(int source, int nodes, vector<pair<int,int>> adj[]){
    vector<int> visited(nodes+1,0);
    vector<int> dist(nodes+1, 9999);
    stack<int> s;
    for(int i=1; i<=nodes; i++){
        if(!visited[i])
            topoSort(i,s,adj,visited);
    }
    dist[source]=0;
    
    while(!s.empty()){
        int node = s.top();
        s.pop();
        for(auto it:adj[node]){
            int v = it.first;
            int w = it.second;
            if(dist[node]+w<dist[v])
                dist[v]= w + dist[node];
        }
    }
    return dist;
}

int main(){
    int nodes, edges;
    cout<<"Enter total number of nodes and edges: ";
    cin>>nodes>>edges;
    vector<pair<int,int>> adj[nodes+1];
    createAdjList(edges,adj);
    cout<<"Enter the source node: ";
    int src;
    cin>>src;
    vector<int> distance = shortestPath(src,nodes,adj);
    for(int i = 1; i<=nodes; i++){
        if(distance[i]==9999)
            distance[i]=-1;
        cout<<distance[i]<<" ";
    }

    return 0;
}