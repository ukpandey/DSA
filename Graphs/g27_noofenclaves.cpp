class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> board,vector<vector<int>> &vis, int n, int m, vector<int> drow, vector<int> dcol){
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int newR = row+drow[i];
            int newC = col+dcol[i];
            if(newR<n && newR>=0 && newC<m && newC>=0 && vis[newR][newC] == 0 && board[newR][newC] == 1){
                dfs(newR,newC,board,vis,n,m,drow,dcol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> drow = {-1,1,0,0};
        vector<int> dcol = {0,0,-1,1};
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i] == 1){
                dfs(0,i,board,vis,n,m,drow,dcol);
            }
            if(!vis[n-1][i] && board[n-1][i] == 1){
                dfs(n-1,i,board,vis,n,m,drow,dcol);
            }
        }

        for(int j=0;j<n;j++){
            if(!vis[j][0] && board[j][0] == 1){
                dfs(j,0,board,vis,n,m,drow,dcol);
            }
            if(!vis[j][m-1] && board[j][m-1] == 1){
                dfs(j,m-1,board,vis,n,m,drow,dcol);
            }
        }
        int c=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 1){
                    c++;
                }
            }
        }
        return c;
    }
};