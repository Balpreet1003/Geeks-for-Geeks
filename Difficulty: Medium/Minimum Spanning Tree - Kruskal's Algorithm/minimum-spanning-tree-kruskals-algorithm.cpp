// User function Template for C++
class Solution {
    int findParent(vector<int>&parent, int node){
        if(parent[node]==node)
            return node;
        return parent[node]=findParent(parent, parent[node]);
    }
    void unionSet(int u, int v, vector<int>&parent, vector<int>&rank){
        u=findParent(parent, u);
        v=findParent(parent, v);
        if(rank[v]<rank[u]){
            parent[v]=u;
        }
        else if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    static bool cmd(vector<int>&a, vector<int>& b){
        return a[2]<b[2];
    }
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<int>parent(V, 0), rank(V, 0);
        for(int i=0;i<V;i++)parent[i]=i;
        sort(edges.begin(), edges.end(), cmd);
        
        int ans=0;
        for(auto x:edges){
            int u=findParent(parent, x[0]);
            int v=findParent(parent, x[1]);
            int wt=x[2];
            
            if(u!=v){
                ans+=wt;
                unionSet(u, v, parent, rank);
            }
        }
        return ans;
    }
};