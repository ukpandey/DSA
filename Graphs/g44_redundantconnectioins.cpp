class DSU{
private:
    vector<int> parent, size;
public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findUltimatePar(int u){
        if(u == parent[u]) return u;
        return parent[u] = findUltimatePar(parent[u]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUltimatePar(u);
        int ulp_v = findUltimatePar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size()+1);
        vector<int> freeEdges(2);
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            if(dsu.findUltimatePar(u) == dsu.findUltimatePar(v)){
                freeEdges[0] = u;
                freeEdges[1] = v;
            }
            else{
                dsu.unionBySize(u,v);
            }
        }
        return freeEdges;
    }
};
/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, 
with one additional edge added. The added edge has two different vertices chosen 
from 1 to n, and was not an edge that already existed. The graph is represented 
as an array edges of length n where edges[i] = [ai, bi] indicates that there is an 
edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. 
If there are multiple answers, return the answer that occurs last in the input.
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
https://leetcode.com/problems/redundant-connection/description/