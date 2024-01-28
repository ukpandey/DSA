#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void createList(int edges, vector<int> adj[])
{
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

vector<int> bfsTraversal(int nodes, vector<int> adj[])
{
    vector<int> ans;
    vector<int> visited(nodes + 1, 0);
    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty())
            {
                int front = q.front();
                ans.push_back(front);
                q.pop();
                for (auto it : adj[front])
                {
                    if (!visited[it])
                    {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }
    return ans;
}
int main()
{
    int nodes, edges;
    cout << "Enter total number of nodes and edges: ";
    cin >> nodes >> edges;
    vector<int> adj[nodes + 1];
    createList(edges, adj);
    vector<int> ans = bfsTraversal(nodes, adj);

    for (auto it : ans)
        cout << it << " ";
}