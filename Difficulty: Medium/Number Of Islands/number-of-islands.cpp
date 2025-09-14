class Solution {
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, -1, 0, 1};

    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);
        if (u == v) return;  // already in same set
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[v] < rank[u]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }

    bool isValid(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
        vector<int> parent(n * m), rank(n * m, 0);
        for (int i = 0; i < n * m; i++)
            parent[i] = i;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<int> ans;
        int count = 0;

        for (auto& op : operators) {
            int x = op[0], y = op[1];
            int idx = x * m + y;

            if (vis[x][y]) {  // already land
                ans.push_back(count);
                continue;
            }

            vis[x][y] = true;
            count++;  // new island

            for (int i = 0; i < 4; i++) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                int adj = x1 * m + y1;

                if (isValid(x1, y1, n, m) && vis[x1][y1]) {
                    int p1 = findParent(parent, idx);
                    int p2 = findParent(parent, adj);
                    if (p1 != p2) {
                        unionSet(p1, p2, parent, rank);
                        count--;  // merged islands
                    }
                }
            }

            ans.push_back(count);
        }
        return ans;
    }
};