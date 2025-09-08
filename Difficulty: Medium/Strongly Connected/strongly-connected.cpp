//Position this line where user code will be pasted.
class Solution {
    stack<int>st;
    bool flag=true;
    vector<bool>vis;
    void dfs(vector<vector<int>>& adj, int i){
        vis[i]=true;
        for(int x:adj[i]){
            if(!vis[x]){
                dfs(adj, x);
            }
        }
        if(flag)
            st.push(i);
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int n=adj.size();
        vis.resize(n, false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj, i);
            }
        }
        fill(vis.begin(), vis.end(), false);
        vector<vector<int>>new_adj(n);
        for(int i=0;i<n;i++){
            for(int x:adj[i]){
                new_adj[x].push_back(i);
            }
        }
        int ans=0;
        flag=false;
        while(!st.empty()){
            int node=st.top(); st.pop();
            if(!vis[node]){
                dfs(new_adj, node);
                ans++;
            }
        }
        return ans;
    }
};