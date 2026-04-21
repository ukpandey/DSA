#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(vector<vector<int>> &image,vector<vector<int>> &ans, int color,
     int oldcolor, int drow[], int dcol[], int n,
     int m, int sr, int sc ){

        ans[sr][sc] = color;

        for(int i=0;i<4;i++){
            int newr = sr+drow[i];
            int newc = sc+dcol[i];
            if(newr>=0 && newc>=0 && newr<n && newc<m && ans[newr][newc]!= color &&
            image[newr][newc] == oldcolor){
                dfs(image,ans,color,oldcolor,drow,dcol,n,m,newr,newc);
            }
        }
     }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int n = image.size();
        int m = image[0].size();
        int oldcolor = image[sr][sc];
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,-1,0,1};
        dfs(image,ans,color,oldcolor,drow,dcol,n,m,sr,sc);
        return ans;
    }
};