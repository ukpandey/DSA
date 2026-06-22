class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1 && grid[0][0]==0) return 1;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0] = 1;
        vector<pair<int,int>> deltaRC = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0}, {1,-1},{0,-1}};
        queue<pair<int,int>> q; 
        q.push({0,0});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int newR = row + deltaRC[i].first;
                int newC = col + deltaRC[i].second;
                if(newR<n && newR>=0 && newC<n && newC>=0 && grid[newR][newC] == 0 && dist[row][col]+1 < dist[newR][newC]){
                    dist[newR][newC] = dist[row][col]+1;
                    if(newR==n-1 && newC==n-1) return dist[newR][newC];
                    q.push({newR,newC});
                }
            }
        }
        return -1;
    }
};

// Input: grid = [[0,1],[1,0]]
// Output: 2
// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4
// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1
// [[0]] output = 1

// Given an n x n binary matrix grid, return the length of the shortest 
// clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell 
// (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected
//  (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.
// https://leetcode.com/problems/shortest-path-in-binary-matrix/