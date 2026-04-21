#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // DFS function to detect cycle and mark safe nodes
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[], int safe[]) {
        vis[node] = 1;
        pathVis[node] = 1;
        safe[node] = 0; // assume not safe

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, adj, vis, pathVis, safe)) {
                    return true;
                }
            } else if (pathVis[neighbor]) {
                return true; // cycle detected
            }
        }

        safe[node] = 1; // mark safe
        pathVis[node] = 0; // backtrack
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V] = {0}, pathVis[V] = {0}, safe[V] = {0};
        vector<int> result;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, pathVis, safe);
            }
        }

        for (int i = 0; i < V; i++) {
            if (safe[i]) result.push_back(i);
        }
        return result;
    }
};

int main() {
    vector<int> adj[12] = {
        {1}, {2}, {3}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, {8}, {9}
    };
    Solution obj;
    vector<int> safe = obj.eventualSafeNodes(12, adj);
    for (int node : safe) cout << node << " ";
    return 0;
}
