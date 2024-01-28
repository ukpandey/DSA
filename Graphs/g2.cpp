#include <iostream>
#include <vector>
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

int main()
{

    int nodes, edges;
    cout << "Enter total number of nodes and edges: ";
    cin >> nodes >> edges;
    vector<pair<int, int>> adj[nodes + 1];

    createWeightedGraph(nodes,edges,adj);

    for (int i = 1; i <= nodes; i++)
    {
        cout << i << ": ";
        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
        {
            cout <<" ("<< it->first << ", " << it->second << ")";
        }
        cout << endl;
    }

    return 0;
}