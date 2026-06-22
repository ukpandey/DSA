class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        visit[node] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] && !visit[i]) {
                dfs(i, isConnected, visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numberOfComponents = 0;
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfComponents++;
                dfs(i, isConnected, visit);
            }
        }

        return numberOfComponents;
    }
};
/*
There are n cities. Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected directly 
with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other 
cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if 
the ith city and the jth city are directly connected, and isConnected[i][j] = 0 
otherwise.

Return the total number of provinces

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
https://leetcode.com/problems/number-of-provinces/description/