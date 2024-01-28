#include<iostream>
#include<vector>
using namespace std;

int timer = 1;

void createAdjList(int edges, vector<int> adj[]){
    int u,v;
    for(int i=0; i<edges; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cout<<i<<endl;
    }
}

void dfs(int node, int par, vector<int> &visited, vector<int> adj[],
         vector<int> &timeOfInsertion, vector<int> &lowestTime, 
         vector<vector<int>> &bridges){
    timeOfInsertion[node] = lowestTime[node] = timer;
    timer++;
    visited[node] = 1;
    for(auto it: adj[node]){
        if(it == par) continue;
        if(!visited[it]){
            dfs(it,node,visited,adj,timeOfInsertion, lowestTime, bridges);
            lowestTime[node] = min(lowestTime[node], lowestTime[it]);
            // check for bridge
            if(timeOfInsertion[node]<lowestTime[it])
                bridges.push_back({it,node});
        }
        else{
            lowestTime[node] = min(lowestTime[node], lowestTime[it]);
        }
    }

}

vector<vector<int>> criticalConnections(int nodes, vector<int> adj[]){
    vector<int> timeOfInsertion(nodes);
    vector<int> lowestTime(nodes);
    vector<int> visited(nodes,0);
    vector<vector<int>> brdiges;
    dfs(0,-1,visited,adj,timeOfInsertion,lowestTime,brdiges);
    return brdiges;

}

int main(){
    int nodes, edges;
    cout<<"Enter total number of nodes and edges: ";
    cin>>nodes>>edges;
    vector<int> adj[nodes];
    createAdjList(edges, adj);
    vector<vector<int>> bridges = criticalConnections(nodes, adj);
    for(int i =0; i<bridges.size(); i++){
        for(auto it: bridges[i])
            cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}