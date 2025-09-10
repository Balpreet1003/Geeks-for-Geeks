class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<pair<int, int>>>adj;
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        
        vector<int>key(V,INT_MAX), parent(V,-1);
        vector<bool>vis(V, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        key[0]=0;
        pq.push({0,0});
        for(int i=0;i<V;i++){
            // int node=i;
            // for(int j=0;j<V;j++){
            //     if(key[j]<key[node] && !vis[j]){
            //         node=j;
            //     }
            // }
            while(!pq.empty() && vis[pq.top().second])
                pq.pop();
            int node=pq.top().second;
            vis[node]=true;
            for(auto x:adj[node]){
                if(!vis[x.first] && x.second<key[x.first]){
                    parent[x.first]=node;
                    key[x.first]=x.second;
                    pq.push({x.second, x.first});
                }
            }
        }
        return accumulate(key.begin(), key.end(), 0);
    }
};