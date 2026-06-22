class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int>> deltaRC = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        priority_queue< pair<int,pair<int,int>>,  vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1) return diff;
            for(int i=0;i<4;i++){
                int newR = row + deltaRC[i].first;
                int newC = col + deltaRC[i].second;
                if(newR<n && newC<m && newR>=0 && newC>=0){
                    int newEffort = max( abs( mat[row][col]-mat[newR][newC] ), diff);
                    if(newEffort < dist[newR][newC]){
                        dist[newR][newC] = newEffort;
                        pq.push({newEffort,{newR,newC}});
                    }
                }
            }
        }
        return 0;
    }
};


/*
You are a hiker preparing for an upcoming hike. You are given heights, 
a 2D array of size rows x columns, where heights[row][col] represents the height 
of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to 
travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 
You can move up, down, left, or right, and you wish to find a route that 
requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two 
consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the 
bottom-right cell.

Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 
in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute 
difference is 3.
https://leetcode.com/problems/path-with-minimum-effort/description/
*/