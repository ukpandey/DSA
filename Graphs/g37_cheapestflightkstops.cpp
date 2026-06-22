class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }
        vector<int> dist(n,1e9);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>> q;
        // steps,node,distance
        q.push({0,{src,0}});
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(steps > k) continue;
            for(auto it:adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                if(cost+edgeWt < dist[adjNode] && steps <= k){
                    dist[adjNode] = cost + edgeWt;
                    q.push({steps+1,{adjNode,dist[adjNode]}});
                }
            }

        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};

/*
There are n cities connected by some number of flights. You are given an array 
flights where flights[i] = [fromi, toi, pricei] indicates that there is a 
flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price 
from src to dst with at most k stops. If there is no such route, return -1.

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], 
src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has 
cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid 
because it uses 2 stops.
https://leetcode.com/problems/cheapest-flights-within-k-stops/
*/