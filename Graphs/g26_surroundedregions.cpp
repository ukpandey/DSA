int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> drow = {-1,1,0,0};
        vector<int> dcol = {0,0,-1,1};
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i] == 'O'){
                dfs(0,i,board,vis,n,m,drow,dcol);
            }
            if(!vis[n-1][i] && board[n-1][i] == 'O'){
                dfs(n-1,i,board,vis,n,m,drow,dcol);
            }
        }

        for(int j=0;j<n;j++){
            if(!vis[j][0] && board[j][0] == 'O'){
                dfs(j,0,board,vis,n,m,drow,dcol);
            }
            if(!vis[j][m-1] && board[j][m-1] == 'O'){
                dfs(j,m-1,board,vis,n,m,drow,dcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

//         Input: board = [["X","X","X","X"],
//                         ["X","O","O","X"],
//                         ["X","X","O","X"],
//                         ["X","O","X","X"]]

// Output: [["X","X","X","X"],
//          ["X","X","X","X"],
//          ["X","X","X","X"],
//          ["X","O","X","X"]]


