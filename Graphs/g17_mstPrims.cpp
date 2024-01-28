#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void createAdjacencyList(int edges, vector<pair<int,int>> adj[]){
    int u,v,wt;
    for(int i=0;i<edges;i++){
        cin>>u>>v>>wt;
        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }
}

vector<pair<int,pair<int,int>>> MST(int nodes, vector<pair<int,int>> adj[]){
    int sum = 0;
    vector<int> visited(nodes, 0);
    priority_queue<pair<int,pair<int,int>>, 
    vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,-1}});
    vector<pair<int,pair<int,int>>> mstEdges;
    while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();
        if(visited[node])
            continue;
        visited[node]=1;
        sum+=wt;
        mstEdges.push_back({par,{node,wt}});
        for(auto it:adj[node]){
            if(!visited[it.first])
                pq.push({it.second,{it.first,node}});
        }
    }
    cout<<"Sum of MST: "<<sum<<endl;
    return mstEdges;
}

int main(){
    int nodes, edges;
    cout<<"Enter total number of nodes and edges: ";
    cin>>nodes>>edges;
    vector<pair<int,int>> adj[nodes];
    createAdjacencyList(edges,adj);
    vector<pair<int,pair<int,int>>>  ans = MST(nodes,adj);
    ans.erase(ans.begin());
    cout<<"U V W\n";
    for(auto it:ans)
        cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<" \n";
}