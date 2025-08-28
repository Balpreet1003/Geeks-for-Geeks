class Solution {
    vector<int> bfs(const vector<vector<int>>& adj, vector<char>& vis, int s) {
        queue<int> q;
        q.push(s);
        vis[s] = 1;                  // mark when enqueuing
        vector<int> comp;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            comp.push_back(u);
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return comp;
    }

public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        adj.reserve(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            // assumes 0 <= u,v < V
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<char> visited(V, 0);  // vector<char> is lighter than vector<bool>
        vector<vector<int>> comps;
        comps.reserve(V);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                comps.push_back(bfs(adj, visited, i));
            }
        }
        return comps;
    }
};
