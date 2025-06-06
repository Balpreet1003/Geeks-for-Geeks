// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>dis(V,1e8);
        dis[src]=0;
        
        for(int i=1;i<V;i++){
            for(auto x:edges){
                if(dis[x[0]]!=1e8 && dis[x[0]]+x[2]<dis[x[1]]){
                    dis[x[1]]=dis[x[0]]+x[2];
                }
            }
        }
        for(auto x:edges){
            if(dis[x[0]]!=1e8 && dis[x[0]]+x[2]<dis[x[1]]){
                return {-1};
            }
        }
        return dis;
    }
};

