class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> vis(V, false);

        for (int start = 0; start < V; start++) {
            if (!vis[start]) {
                queue<pair<int, int>> q;
                q.push({start, -1});
                vis[start] = true;

                while (!q.empty()) {
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();

                    for (int i : adj[node]) {
                        if (!vis[i]) {
                            q.push({i, node});
                            vis[i] = true;  // ✅ fix here
                        } else if (i != parent) {
                            return true;  // Cycle detected
                        }
                    }
                }
            }
        }
        return false;  // No cycle in any component
    }
};