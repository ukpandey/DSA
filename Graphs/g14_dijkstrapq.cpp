#include <iostream>
#include <vector>
#include<queue>
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

vector<int> shortestPath(int nodes, int src, vector<pair<int,int>> adj[]){
    vector<int> dist(nodes+1,9999);
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
    vector<int> ans = shortestPath(nodes,src,adj);
     for(int i = 1; i < nodes+1; i++){
        if(ans[i]==9999)
            ans[i]=-1;
        cout<<ans[i]<<" ";
    }
 

    return 0;
}