class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> drow = {-1,1,0,0};
        vector<int> dcol = {0,0,-1,1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;
            for(int i=0;i<4;i++){
                int newR = row+drow[i];
                int newC = col+dcol[i];
                if(newR<n && newR>=0 && newC<m && newC>=0 && vis[newR][newC] == 0){
                    vis[newR][newC]=1;
                    q.push({{newR,newC},steps+1});
                }
            }
        }
        return dist;
    }
};
// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two cells sharing a common edge is 1
// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]