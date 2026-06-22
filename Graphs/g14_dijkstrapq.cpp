#include <iostream>
#include <vector>
#include<queue>
#include <algorithm>
using namespace std;

void createWeightedGraph(int nodes, int edges, vector<pair<int, int>> adj[])
{
    int u, v, wt;
    for (int i = 0; i < edges; i++)
    {
        cin>>u>>v>>wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }
}

vector<int> shortestPath(int nodes, int src, vector<pair<int,int>> adj[], vector<int> &parent){
    vector<int> dist(nodes+1,9999);
    for(int i=1;i<nodes;i++){
        parent[i] = i;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        for(auto it: adj[node]){
            int adjNode = it.first;
            int edgeWt = it.second;
            if(distance+edgeWt<dist[adjNode]){
                parent[adjNode] = node;
                dist[adjNode]= distance+edgeWt;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

int main()
{

    int nodes, edges;
    cout << "Enter total number of nodes and edges: ";
    cin >> nodes >> edges;
    vector<pair<int, int>> adj[nodes + 1];

    createWeightedGraph(nodes,edges,adj);
    cout<<"Enter the source: ";
    int src;
    cin>>src;
    vector<int> parent(nodes+1);
    vector<int> ans = shortestPath(nodes,src,adj,parent);
    vector<int> path;
    if(ans[nodes]==9999) cout<<"Path not found"<<endl;
    int node = nodes;
    while(parent[node]!=node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
     for(int i = 1; i < nodes+1; i++){
        if(ans[i]==9999)
            ans[i]=-1;
        cout<<ans[i]<<" ";
    }
 

    return 0;
}