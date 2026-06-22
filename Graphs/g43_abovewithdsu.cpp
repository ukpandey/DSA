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
    int makeConnected(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int freeEdges=0;
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            if(dsu.findUltimatePar(u) == dsu.findUltimatePar(v)){
                freeEdges++;
            }
            else{
                dsu.unionBySize(u,v);
            }
        }
        int components = 0;
        for(int i=0;i<n;i++){
            if(dsu.findUltimatePar(i) == i){
                components++;
            }
        }
        if(freeEdges < components-1) return -1;
        return components-1;
    }
};