// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int, vector<pair<int,int>>>adj;
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        q.push({0,src});
        vector<int>ans(V, INT_MAX);
        ans[src]=0;
        while(!q.empty()){
            int node=q.top().second;
            int wt=q.top().first;
            q.pop();
            
            for(auto x:adj[node]){
                if(ans[x.first]>wt+x.second){
                    ans[x.first]=wt+x.second;
                    q.push({ans[x.first],x.first});
                }
            }
        }
        return ans;
    }
};