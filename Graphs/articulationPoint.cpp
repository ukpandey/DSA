// #include<iostream>
// #include<queue>
// #include<vector>
// using namespace std;
// void dfs(vector<int> adj[],int &timer,int node, vector<int> &visited, vector<int> &disc,vector<int> &low,int &parent,vector<vector<int>> &result ){
//     visited[node]=1;
//     disc[node]=low[node]=timer++;
//     for(auto nbr:adj[node]){
//         if(nbr==parent)
//             continue;
//         if(!visited[nbr]){
//             dfs(adj,timer,nbr,visited,disc,low,node,result);
//             low[node]=min(low[node],low[nbr]);
//             // check bridge
//             if(low[nbr]>disc[node]){
//                 cout<<node<<" "<<nbr<<endl;
//             }
//         }
//         else{ //backedge case
//                 low[node]=min(low[node],disc[nbr]);
//         }
//     }

// }
// void bridge(vector<int> adj[],int n){
//     int timer=0;
//     vector<vector<int>> result;
//     vector<int> visited(n+1,0);
//     vector<int> disc(n+1,-1);
//     vector<int> low(n+1,-1);
//     int parent=-1;
//     for(int i=1;i<=n;i++){
//         if(!visited[i]){
//             dfs(adj,timer,i,visited,disc,low,parent,result);
//         }
//     }

// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<int> adj[n+1];
//     for(int i=1;i<=m;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     bridge(adj,n);
    
//     return 0;
// }
// C++ program to find articulation points in an undirected graph
#include <bits/stdc++.h>
using namespace std;

// A recursive function that find articulation
// points using DFS traversal
// adj[] --> Adjacency List representation of the graph
// u --> The vertex to be visited next
// visited[] --> keeps track of visited vertices
// disc[] --> Stores discovery times of visited vertices
// low[] -- >> earliest visited vertex (the vertex with minimum
// discovery time) that can be reached from subtree
// rooted with current vertex
// parent --> Stores the parent vertex in DFS tree
// isAP[] --> Stores articulation points
void APUtil(vector<int> adj[], int u, bool visited[],
			int disc[], int low[], int& time, int parent,
			bool isAP[])
{
	// Count of children in DFS Tree
	int children = 0;

	// Mark the current node as visited
	visited[u] = true;

	// Initialize discovery time and low value
	disc[u] = low[u] = ++time;

	// Go through all vertices adjacent to this
	for (auto v : adj[u]) {
		// If v is not visited yet, then make it a child of u
		// in DFS tree and recur for it
		if (!visited[v]) {
			children++;
			APUtil(adj, v, visited, disc, low, time, u, isAP);

			// Check if the subtree rooted with v has
			// a connection to one of the ancestors of u
			low[u] = min(low[u], low[v]);

			// If u is not root and low value of one of
			// its child is more than discovery value of u.
			if (parent != -1 && low[v] >= disc[u])
				isAP[u] = true;
		}

		// Update low value of u for parent function calls.
		else if (v != parent)
			low[u] = min(low[u], disc[v]);
	}

	// If u is root of DFS tree and has two or more children.
	if (parent == -1 && children > 1)
		isAP[u] = true;
}

void AP(vector<int> adj[], int V)
{
	int disc[V] = { 0 };
	int low[V];
	bool visited[V] = { false };
	bool isAP[V] = { false };
	int time = 0, par = -1;

	// Adding this loop so that the
	// code works even if we are given
	// disconnected graph
	for (int u = 0; u < V; u++)
		if (!visited[u])
			APUtil(adj, u, visited, disc, low,
				time, par, isAP);

	// Printing the APs
	for (int u = 0; u < V; u++)
		if (isAP[u] == true)
			cout << u << " ";
}

// Utility function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	// Create graphs given in above diagrams
	cout << "Articulation points in first graph \n";
	int V = 5;
	vector<int> adj1[V];
	addEdge(adj1, 0, 3);
	addEdge(adj1, 0, 1);
	addEdge(adj1, 2, 1);
	addEdge(adj1, 0, 4);
	addEdge(adj1, 3, 4);
	AP(adj1, V);

	cout << "\nArticulation points in second graph \n";
	V = 4;
	vector<int> adj2[V];
	addEdge(adj2, 0, 1);
	addEdge(adj2, 1, 2);
	addEdge(adj2, 2, 3);
	AP(adj2, V);

	cout << "\nArticulation points in third graph \n";
	V = 7;
	vector<int> adj3[V];
	addEdge(adj3, 0, 1);
	addEdge(adj3, 1, 2);
	addEdge(adj3, 2, 0);
	addEdge(adj3, 1, 3);
	addEdge(adj3, 1, 4);
	addEdge(adj3, 1, 6);
	addEdge(adj3, 3, 5);
	addEdge(adj3, 4, 5);
	AP(adj3, V);

	return 0;
}
