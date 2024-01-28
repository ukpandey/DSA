#include <iostream>
#include <vector>
using namespace std;

void createWeightedGraph(int edges, vector<pair<int, int>> adj[])
{
    int u, v, w;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
}

vector<int> bellmanford(int nodes, vector<pair<int, int>> adj[], int src)
{
    vector<int> dist(nodes + 1, 9999);
    dist[src] = 0;
    // relaxing edges n-1 times
    for (int i = 0; i < nodes - 1; i++)
    {   // traversing all the edges
        for (int u = 1; u <= nodes; u++)
        { 

            for (auto it : adj[u])
            {
                int v = it.first;
                int wt = it.second;
                if (dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }

    // relaxing the edges nth time to check negative cycle
    for (int u = 1; u <= nodes; u++)
    {
        for (auto it : adj[u])
        {
            int v = it.first;
            int wt = it.second;
            if (dist[u] + wt < dist[v])
            {
                cout<<"Negative Cycle is present"<<endl;
                return dist;
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
    createWeightedGraph(edges, adj);
    cout<<"Enter the source: ";
    int src;
    cin>>src;
    vector<int> ans = bellmanford(nodes,adj,src);
    for(int i=1;i<nodes+1; i++)
        cout<<ans[i]<<" ";
    return 0;
}