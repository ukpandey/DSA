#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool iscycleDFS(int node, vector<int> &visited, int parent, vector<int> adj[])
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            if (iscycleDFS(it, visited, node, adj))
                return true;
        }
        else if (parent != it)
            return true;
    }
    return false;
}

bool isCycle(int n, vector<int> &visited, vector<int> adj[])
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            // isCycleDFS(i,visited,-1,adj);
            if (iscycleDFS(i, visited, -1, adj))
                return true;
        }
    }
    return false;
}
int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ":  ";
        for (auto it = adj[i].begin(); it != adj[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    vector<int> visited(n + 1, 0);

    if (isCycle(n, visited, adj))
        cout << "Cycle is present";
    else
        cout << "Cycle is not present";

    return 0;
}