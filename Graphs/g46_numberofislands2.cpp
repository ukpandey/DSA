#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (DSU) class
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]); // Path compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Solution to find the number of islands after each operation
class Solution {
private:
    // Helper function to check if a cell is within bounds
    bool isValid(int adjr, int adjc, int n, int m) {
        return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
    }

public:
    // Main function to process all operators and count number of islands
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
        DisjointSet ds(n * m); // Disjoint set to manage connected land cells
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        vector<int> ans;

        for (auto it : operators) {
            int row = it[0], col = it[1];

            // Skip if the cell is already land
            if (vis[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }

            // Mark cell as land
            vis[row][col] = 1;
            cnt++;

            // Directions to check for adjacent cells (up, right, down, left)
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int ind = 0; ind < 4; ind++) {
                int adjr = row + dr[ind], adjc = col + dc[ind];
                if (isValid(adjr, adjc, n, m)) {
                    if (vis[adjr][adjc] == 1) {
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;
                        if (ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)) {
                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }

            ans.push_back(cnt);
        }
        return ans;
    }
};

int main() {
    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };

    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, operators);
    for (auto res : ans) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
/*
Problem Statement: You are given an n, m which means the row and column of the 
2D matrix, and an array of size k denoting the number of operations. Matrix elements 
are 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 
which means there is no land in the matrix. The array has k operator(s) and each 
operator has two integers A[i][0], A[i][1] means that you can change the cell 
matrix[A[i][0]][A[i][1]] from sea to island. Return how many islands are there in the 
matrix after each operation. You need to return an array of size k.

Note: An island means a group of 1s such that they share a common side.
Example 1:
Input Format: n = 4 m = 5 k = 4 A = {{1,1},{0,1},{3,3},{3,4}} 
Output: 1 1 2 2 
Explanation: The following illustration is the representation of the operation:

Example 2:
Input Format: n = 4 m = 5 k = 12 A = {{0,0},{0,0},{1,1},{1,0},{0,1},{0,3},{1,3},{0,4}, {3,2}, {2,2},{1,2}, {0,2}} 
Output: 1 1 2 1 1 2 2 2 3 3 1 1 
Explanation: If we follow the process like in example 1, we will get the above result.
