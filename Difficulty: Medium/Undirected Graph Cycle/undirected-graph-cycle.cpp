class Solution {
    bool bfs(unordered_map<int, vector<int>>& adj, vector<bool>&vis, int i){
        queue<pair<int,int>>q;
        q.push({i,-1});
        vis[i]=true;
        
        while(!q.empty()){
            pair<int,int>x=q.front(); q.pop();
            int node=x.first;
            int par=x.second;
            
            for(int child:adj[node]){
                if(!vis[child]){
                    vis[child]=true;
                    q.push({child, node});
                }
                else if(child!=par)
                    return true;
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> vis(V, false);

        for (int start = 0; start < V; start++) {
            if (!vis[start]) {
                if(bfs(adj, vis, start)) 
                    return true;
            }
        }
        return false;
    }
};