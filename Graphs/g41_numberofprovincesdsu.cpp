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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        int provinces = n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] && dsu.findUltimatePar(i)!=dsu.findUltimatePar(j)){
                    provinces--;
                    dsu.unionBySize(i,j);
                }
            }
        }
        return provinces;
    }
};