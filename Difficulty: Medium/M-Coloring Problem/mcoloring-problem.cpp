//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    unordered_map<int,vector<int>>adj;
    vector<int>vis;
    bool solve(int & m, int& v, int node){
        if(node==v){
            return true;
        }
        for(int i=0;i<m;i++){
            bool flag=true;
            for(auto child:adj[node]){
                if(vis[child]==i){
                    flag=false;
                    break;
                }
            }
            if(flag){
                vis[node]=i;
                if(solve(m,v,node+1)){
                    return true;
                }
                vis[node]=-1;
            }
        }
        return false;
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vis.resize(v, -1);
        return solve(m, v, 0);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
            edges.push_back({v, u});
        }
        int m;
        cin >> m;
        cin.ignore();

        Solution obj;
        cout << (obj.graphColoring(V, edges, m) ? "true" : "false") << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends