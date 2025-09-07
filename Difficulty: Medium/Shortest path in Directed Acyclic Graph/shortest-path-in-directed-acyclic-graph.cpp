// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
        }
        vector<int>ans(V, INT_MAX);
        queue<int>q;
        q.push(0);
        ans[0]=0;
        while(!q.empty()){
            int node=q.front(); q.pop();
            for(auto x:adj[node]){
                if(ans[x.first]>(ans[node]+x.second)){
                    ans[x.first]=ans[node]+x.second;
                    q.push(x.first);
                }
            }
        }
        for(int i=0;i<V;i++)
            if(ans[i]==INT_MAX)
                ans[i]=-1;
                
        return ans;
    }
};
