// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        const int MOD = 1e5;
        vector<int> dis(MOD, INT_MAX);
        queue<pair<int, int>> q;

        dis[start] = 0;
        q.push({start, 0});

        while (!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (auto x : arr) {
                int newNode = (node * x) % MOD;

                if (steps + 1 < dis[newNode]) {
                    dis[newNode] = steps + 1;
                    if (newNode == end) return dis[newNode];
                    q.push({newNode, steps + 1});
                }
            }
        }

        return (start == end) ? 0 : (dis[end] == INT_MAX ? -1 : dis[end]);
    }
};
