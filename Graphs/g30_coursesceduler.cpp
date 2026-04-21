class Solution {
private:
    void bfs(int n, vector<int> adj[], vector<int>& indegree, vector<int>& toposort){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            toposort.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(auto edge:edges){
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        vector<int> toposort;
        bfs(n,adj,indegree,toposort);
        if(toposort.size()==n) return toposort;
        return {};
    }
};