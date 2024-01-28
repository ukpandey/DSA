#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void weightedGraph(int nodes, int edges, vector<pair<int,int>> adjWt[]){
    int u,v,wt;
    for(int i=1;i<=nodes;i++){
        cin>>u>>v>>wt;
        adjWt[u].push_back(make_pair(v,wt));
        adjWt[v].push_back(make_pair(u,wt));
    }
}
void createAdjacencyList(int nodes, int edges, vector<int> adj[]){
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
}

void bfsTraversal(int nodes, int edges, vector<int> adj[]){
    // vector<int> bfs;
    vector<int> visited(nodes+1,0);
    for(int i=1;i<=nodes;i++){
        if(!visited[i]){
            queue<int> q; 
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
                int front = q.front();
                q.pop();
                cout<<front<<" ";
                for(auto it=adj[front].begin();it!=adj[front].end();it++){
                    if(!visited[*it]){
                        q.push(*it);
                        visited[*it]=1;
                    }
                }
            }
        }
    }

}

void dfsUtil(int i, vector<int> &visited, vector<int> adj[]){
    cout<<i<<" ";
    visited[i]=1;
    for(auto it:adj[i]){
        if(!visited[it]){
            dfsUtil(it,visited,adj);
        }
    }

}
void dfsTraversal(int nodes, vector<int> adj[]){
    vector<int> visited(nodes+1,0);
    for(int i=1;i<=nodes;i++){
        if(!visited[i])
            dfsUtil(i,visited,adj);
    }
}
int main(){
    cout<<"Enter number of nodes: ";
    int n;
    cin>>n;
    cout<<"Enter the edges: ";
    int m;
    cin>>m;
   // vector<int> adj[n+1];
    vector<pair<int,int>> adjWt[n+1];
    //createAdjacencyList(n,m,adj);
    // for (int i = 1; i < n+1; i++) {
  
    //     cout << "Elements at index "<< i << ": ";
  
        
    //     for (auto it = adj[i].begin();  it != adj[i].end(); it++) {
  
           
    //         cout << *it << ' ';
    //     }
    //     cout << endl;
    // }
    weightedGraph(n,m,adjWt);
    for(int i=1;i<=n;i++){
        cout<<i<<": ";
        for(auto it = adjWt[i].begin(); it!=adjWt[i].end(); it++){
            cout<<it->first<<", "<<it->second<<" ";
        }
        cout<<endl;
    }
    // cout<<"BFS: ";
    // bfsTraversal(n,m,adj);
    // cout<<"\nDFS: ";
    // dfsTraversal(n,adj);

} 