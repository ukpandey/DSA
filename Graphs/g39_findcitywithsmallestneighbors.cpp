class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int cityNumber, minNeighbors = 1e9;

        for(int i=0;i<n;i++){
            vector<int> dist(n,1e9);
            dist[i] = 0;
            pq.push({0,i});
            while(!pq.empty()){
                int node = pq.top().second;
                int cost = pq.top().first;
                pq.pop();
                for(auto it:adj[node]){
                    int adjnode = it.first;
                    int edgeWt = it.second;
                    if(cost+edgeWt < dist[adjnode]){
                        dist[adjnode] = cost + edgeWt;
                        pq.push({dist[adjnode],adjnode});
                    }
                }
            }
            int count = 0;
            for(int j=0;j<n;j++){
                if(dist[j]<=distanceThreshold) count++;
            }
            if(count<=minNeighbors){
                minNeighbors = count;
                cityNumber = i;
            }
            
        }
        return cityNumber;
    }
};

/*
There are n cities numbered from 0 to n-1. Given the array edges where 
edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge 
between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through 
some path and whose distance is at most distanceThreshold, If there are multiple 
such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of 
the edges' weights along that path.
Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, 
but we have to return city 3 since it has the greatest number.

https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

use floydwarshall for this problem
*/