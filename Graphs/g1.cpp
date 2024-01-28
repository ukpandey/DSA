#include <iostream>
#include <vector>
using namespace std;

void createAdjList(int nodes, int edges, vector<int> adj[])
{
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // comment this line for directed graphs
    }
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes and edges:  ";
    cin >> nodes >> edges;
    vector<int> adj[nodes + 1];

    createAdjList(nodes,edges,adj);

    for (int i = 1; i < nodes + 1; i++)
    {

        cout << "Elements at index " << i << ": [ ";

        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
        {

            cout << *it<<",";
        }
        cout << "]"<<endl;
    }
}