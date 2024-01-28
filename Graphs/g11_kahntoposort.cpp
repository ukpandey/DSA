#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void kahnTopoSort(int n, vector<int> adj[], vector<int> &indegree){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    int c=0;
    vector<int> ans;
    while(!q.empty()){
        int front =q.front();
        q.pop();
        ans.push_back(front);
        for(auto it=adj[front].begin();it!=adj[front].end();it++){
            indegree[*it]--;
            if(indegree[*it]==0)
                q.push(*it);
             }
            c++;
    }
    if(c!=n){ cout<<"Cycle is present"; return; }
    for(auto it:ans){
        cout<<it<<" ";
    }


}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> visited(n+1,0);
    vector<int> indegree(n+1,0);
    for(int i=1;i<n+1;i++){
        for(auto it=adj[i].begin(); it!=adj[i].end();it++){
            indegree[*it]++;
        }
    }
    kahnTopoSort(n,adj,indegree);
}

