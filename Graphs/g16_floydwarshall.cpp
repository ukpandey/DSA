#include <iostream>
#include <vector>
using namespace std;

void createAdjacencyMatrix(vector<vector<int>> &adj, int edges){
     for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }
}

void floydwarshall(vector<vector<int>> &adj){
    int nodes = adj.size();
    for(int k=0; k<nodes; k++){
        for(int i=0; i<nodes; i++){
            for(int j=0; j<nodes; j++){
                adj[i][j] = min(adj[i][j], (adj[i][k]+adj[k][j]));
            }
        }
    }

    // checking for negative cycle
    for(int i=0; i<nodes; i++){
        if(adj[i][i]<0){
            cout<<"Cycle is Present"<<endl;
            break;
        }
    }
}

int main()
{
    cout << "Enter total number of nodes and edges: ";
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adj(nodes, vector<int>(nodes, 99999));
    for(int i=0; i<nodes; i++)
        adj[i][i]=0;
    createAdjacencyMatrix(adj,edges);
    floydwarshall(adj);

    cout<<"\n\n Resultant Matrix of Shortest Distances:\n\n";
    for (int i = 0; i < nodes; i++)
    {
        for (auto it : adj[i])
        {
            cout << it << "\t";
        }
        cout << endl<<endl;
    }
}