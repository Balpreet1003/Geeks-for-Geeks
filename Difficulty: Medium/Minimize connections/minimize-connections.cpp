// User function Template for C++

class Solution {
    vector<bool>vis;
    pair<int,int>bfs(unordered_map<int,vector<int>>&adj, int i){
        int nodes=0, edges=0;
        queue<int>q;
        q.push(i);
        vis[i]=true;
        while(!q.empty()){
            int node=q.front(); q.pop();
            nodes++;
            
            for(int x:adj[node]){
                edges++;
                if(!vis[x]){
                    q.push(x);
                    vis[x]=true;
                }
            }
        }
        return {edges/2, nodes};
    }
    
  public:
    int minimumConnections(int n, vector<vector<int>> &connections) {
        unordered_map<int,vector<int>>adj;
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vis.resize(n, false);
        int extra=0, components=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                auto x=bfs(adj, i);
                int cnt=x.first;
                int nodes=x.second;
                components++;
                // cout<<nodes<<" "<<cnt<<endl;
                extra+=(max(0,cnt-(nodes-1)));
            }
        }
        // cout<<extra<<" "<<components<<endl;
        return extra>=(components-1) ? components-1 : -1;
    }
};