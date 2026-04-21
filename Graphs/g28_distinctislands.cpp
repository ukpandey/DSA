#include<iostream>
#include<vector>
#include<set>
using namespace std;
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &mat, 
    vector<pair<int,int>> &islands, int baserow, int basecol, int n, int m){

    vis[row][col]=1;
    islands.push_back({row-baserow,col-basecol});
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,-1,0,1};    
    for(int i=0;i<4;i++){
        int newr = row+drow[i];
        int newc = col+dcol[i];
        if(newr<n && newr>=0 && newc<m && newc>=0 && !vis[newr][newc] && mat[newr][newc]==1){
            dfs(newr,newc,vis,mat,islands,baserow,basecol,n,m);
        }
    }

}
int distinctIslands(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>> st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && mat[i][j]==1){
                vector<pair<int,int>> islands;
                dfs(i,j,vis,mat,islands,i,j,n,m);
                st.insert(islands);
            }
        }
    }
    return st.size();
}
int main(){
    vector<vector<int>> mat = {{1,1,0,0},
                               {0,1,0,0},
                               {0,0,1,1},
                               {0,0,0,1}};
    cout<<distinctIslands(mat); // 1
    return 0;
}