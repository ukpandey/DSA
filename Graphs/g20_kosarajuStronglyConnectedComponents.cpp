#include<bits/stdc++.h>
using namespace std;
void dfs(int node, bool visited[], vector<int> adj[], stack<int> &s){
    visited[node]=true;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,visited,adj,s);
        }
    }
    s.push(node);
}
void revDFS(int node, bool visited[],vector<int> transpose[], vector<int> &scc){
    visited[node]=true;
    scc.push_back(node);
    for(auto it:transpose[node]){
        if(!visited[it]){
            revDFS(it,visited,transpose,scc);
        }
    }
}
int main(){
    cout<<"Enter total number of nodes and edges: ";
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool visited[n]={false};
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,visited,adj,s);
        }
    }
    //Transpose;
    vector<int> transpose[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
        for(auto it:adj[i])
            transpose[it].push_back(i);
    }
    int c =0;
    vector<vector<int>> answer;
    while(!s.empty()){
        int top=s.top();
        s.pop();
        if(!visited[top]){
            c++;
            vector<int> scc;
            revDFS(top,visited,transpose,scc);
            answer.push_back(scc);
        }
    }
    cout<<"Count of strongly connected components is: "<<c <<endl;
    cout<<"The strongly connected components are: \n";
    for(int i=0; i<answer.size(); i++){
        for(auto it: answer[i])
            cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}