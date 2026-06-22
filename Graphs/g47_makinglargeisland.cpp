class DSU{   
public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findUltimatePar(int u){
        if(u == parent[u]) return u;
        return parent[u] = findUltimatePar(parent[u]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUltimatePar(u);
        int ulp_v = findUltimatePar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n*n);
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                for(int i=0;i<4;i++){
                    int newR = row+drow[i];
                    int newC = col+dcol[i];
                    if(newR<n && newR>=0 && newC<n && newC>=0 && grid[newR][newC]==1){
                        int node = row*n + col;
                        int adjnode = newR*n + newC;
                        dsu.unionBySize(node,adjnode);
                    }
                }
            }
        }
        int ans = 0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                unordered_set<int> st;
                for(int i=0;i<4;i++){
                    int newR = row+drow[i];
                    int newC = col+dcol[i];
                    if(newR<n && newR>=0 && newC<n && newC>=0 && grid[newR][newC]==1){
                        int adjnode = newR*n + newC;
                        st.insert(dsu.findUltimatePar(adjnode));
                    }
                }
                int totalSize = 1;
                for(auto it:st){
                    totalSize += dsu.size[it];
                }
                ans = max(ans,totalSize);
            }
        }

        // if all elements are 1
        return max(ans, dsu.size[dsu.findUltimatePar(0)]);

    }
};

/*
You are given an n x n binary matrix grid. You are allowed to change at most one 
0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with 
area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island 
with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.

https://leetcode.com/problems/making-a-large-island/description/