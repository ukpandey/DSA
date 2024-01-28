#include <iostream>
#include <vector>
#include<queue>
using namespace std;

void createAdjList(int nodes, int edges, vector<int> adj[])
{
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
}

    vector<int> shortestPath(int nodes, int source, vector<int> adj[]){
        vector<int> dist(nodes+1,9999);
        dist[source]=0;
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dist[node]+1<dist[it]){
                    dist[it]= dist[node]+1;
                    q.push(it);
                }
                    
            }
        }
        return dist;
    }

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes and edges:  ";
    cin >> nodes >> edges;
    vector<int> adj[nodes + 1];

    createAdjList(nodes,edges,adj);
     cout<<"Enter the source: ";
    int src;
    cin>>src;
    vector<int> ans = shortestPath(nodes,src,adj);
    for(int i = 1; i < nodes+1; i++){
        if(ans[i]==9999)
            ans[i]=-1;
        cout<<ans[i]<<" ";
    }
    return 0;

}