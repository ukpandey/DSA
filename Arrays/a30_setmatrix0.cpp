#include<iostream>
#include<vector>
using namespace std;
void markRows(int i, vector<vector<int>> &v, int m){
    for(int j=0; j<m; j++)
        if(v[i][j]!=0)
            v[i][j] = -1;
}
void markColms(int j, vector<vector<int>> &v, int n){
    for(int i=0; i<n; i++)
        if(v[i][j]!=0)
            v[i][j] = -1;
}
// O(n*m*(n+m)) + O(n*m)
void bruteForce(vector<vector<int>> &v){
    int n=v.size();
    int m=v[0].size();
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == 0){
                markRows(i,v,m);
                markColms(j,v,n);
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j]==-1)
                v[i][j] = 0;
        }
    }
}

// O(n*m) and space is O(n+m)
void better(vector<vector<int>> &v){
    int n=v.size();
    int m=v[0].size();
    vector<int> row(n, 0);
    vector<int> col(m,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == 0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(row[i]||col[j])
                v[i][j]=0;
        }
    }
}

void optimal(vector<vector<int>> &v){
    int n=v.size();
    int m=v[0].size();
    int col0=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == 0){
                v[i][0] = 0;
                if(j!=0)
                    v[0][j] = 0;
                else 
                    col0 = 0;

            }
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(v[i][j]!=0){
                if(v[i][0]==0 || v[0][j] == 0 )
                    v[i][j]=0;
            }
        }
    }

    if(v[0][0] == 0){
        for(int j=0; j<m; j++)
            v[0][j] = 0;
    }
    if(col0==0){
        for(int i=0; i<n; i++)
            v[i][0] = 0;
    }
}

int main(){
    vector<vector<int>> v{{1,1,1},
                          {1,0,1},
                          {1,1,1}};

    // bruteForce(v);
    // better(v);
    optimal(v);
    for(auto rows:v){
        for(auto it:rows)
            cout<<it<<" ";
        cout<<endl;
    }
}