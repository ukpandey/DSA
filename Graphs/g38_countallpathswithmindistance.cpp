class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<long long> dist(n,1e18);
        dist[0] = 0;
        vector<int> ways(n,0);
        ways[0] = 1;
        int mod = (int)(1e9+7);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> > pq;
        pq.push({0,0});

        while(!pq.empty()){
            int node = pq.top().second;
            long long wt = pq.top().first;
            pq.pop();
            // if (wt > dist[node]) continue;
            for(auto it:adj[node]){
                int adjnode = it.first;
                int edgeWt  = it.second; 
                if(wt + edgeWt < dist[adjnode]){
                    dist[adjnode] = wt+edgeWt;
                    pq.push({wt+edgeWt,adjnode});
                    ways[adjnode] = ways[node];
                }
                else if(wt + edgeWt == dist[adjnode]){
                    ways[adjnode] = (ways[node] + ways[adjnode])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with
 bi-directional roads between some intersections. The inputs are generated such 
 that you can reach any intersection from any other intersection and that there 
 is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = 
[ui, vi, timei] means that there is a road between intersections ui and vi 
that takes timei minutes to travel. You want to know in how many ways you can travel 
from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount 
of time. Since the answer may be large, return it modulo 109 + 7.

Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],
[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to 
intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
*/