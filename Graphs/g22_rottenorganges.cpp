#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int totalOranges = 0;

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    visited[i][j] = 2;
                    q.push({{i,j},0});
                }
                if(grid[i][j] == 1){
                    totalOranges++;
                }
            }
        }

        for(auto row:visited){
            for(auto it:row){
                cout<<it<<" ";
            }
            cout<<endl;
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int time = 0;
        int count = 0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time,t);
            count += q.size();
            q.pop();

            for(int i=0; i<4; i++){
                int newr = r+dx[i];
                int newc = c+dy[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && 
                visited[newr][newc] == 0 && grid[newr][newc] == 1){
                    visited[newr][newc] = 2;
                    q.push({{newr,newc},t+1});
                    count++;
                }
            }
        }

        return totalOranges == count ? time : -1;

    }

int main(){
        // Input grid with 2 = rotten, 1 = fresh, 0 = empty
    vector<vector<int>> v{{2, 1, 1}, 
                          {1, 1, 0}, 
                          {0, 1, 1}};
    cout<<orangesRotting(v);
    return 0;
}