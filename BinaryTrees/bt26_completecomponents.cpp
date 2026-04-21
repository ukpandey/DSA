class Solution {
private:
    void dfs(vector<int> adj[], vector<int> &visited, int componentInfo[], int i){
        componentInfo[0]++;
        componentInfo[1] += adj[i].size();
        visited[i] = 1;
        for(auto it:adj[i]){
            if(!visited[it]){
                dfs(adj,visited,componentInfo,it);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);;
        }
        vector<int> visited(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            int componentInfo[2] = {0,0};
            if(!visited[i]){
                dfs(adj, visited, componentInfo, i);
                if(componentInfo[0]*(componentInfo[0]-1) == componentInfo[1])
                    ans++;
            }
        }
        return ans;
    }
};

https://leetcode.com/problems/count-the-number-of-complete-components/editorial/#approach-2-depth-first-search-dfs