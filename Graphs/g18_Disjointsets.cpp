#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
    vector<int> rank, par, size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        par.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            par[i]=i;
            size[i]=1;
        }

    }
    
    int findUltimatePar(int node){
        if(node == par[node])
            return node;
        return par[node] = findUltimatePar(par[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUltimatePar(u);
        int ulp_v = findUltimatePar(v);
        if(ulp_u == ulp_v) return;

        if(rank[ulp_u]<rank[ulp_v]){
            par[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            par[ulp_v] = ulp_u;
        }
        else{
            par[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUltimatePar(u);
        int ulp_v = findUltimatePar(v);
        if(ulp_u == ulp_v) return;

        if(size[ulp_u]<size[ulp_v]){
            par[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            par[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

int main(){
    DisjointSet ds(7);
    // ds.unionByRank(1,2);
    // ds.unionByRank(2,3);
    // ds.unionByRank(4,5);
    // ds.unionByRank(6,7);
    // ds.unionByRank(5,6);
    // // check if 3 and 7 are same;
    // if(ds.findUltimatePar(3)==ds.findUltimatePar(7))
    //     cout<<"Same\n";
    // else
    //     cout<<"Not same\n";
    // ds.unionByRank(3,7);

    //     if(ds.findUltimatePar(3)==ds.findUltimatePar(7))
    //     cout<<"Same\n";
    // else
    //     cout<<"Not same\n";

    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    // check if 3 and 7 are same;
    if(ds.findUltimatePar(3)==ds.findUltimatePar(7))
        cout<<"Same\n";
    else
        cout<<"Not same\n";

    ds.unionBySize(3,7);

    if(ds.findUltimatePar(3)==ds.findUltimatePar(7))
        cout<<"Same\n";
    else
        cout<<"Not same\n";
    return 0;
}