class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n=adj.size();
        vector<int>ans(n,-1);
        queue<pair<int,int>>q;
        q.push({src,0});
        vector<int>vis(n,false);
        vis[src]=true;
        while(!q.empty()){
            int node=q.front().first;
            int d=q.front().second;
            q.pop();
            ans[node]=d;
            for(int x:adj[node]){
                if(!vis[x]){
                    vis[x]=true;
                    q.push({x,d+1});
                }
            }
        }
        return ans;
    }
};