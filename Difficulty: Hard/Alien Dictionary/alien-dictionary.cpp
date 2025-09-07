class Solution {
public:
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        for (string &s : words)
            for (char c : s)
                indegree[c] = 0;

        for (int i = 1; i < words.size(); i++) {
            string &w1 = words[i - 1], &w2 = words[i];
            int j = 0, k = 0;
            while (j < w1.size() && k < w2.size()) {
                if (w1[j] != w2[k]) {
                    adj[w1[j]].push_back(w2[k]);
                    indegree[w2[k]]++;
                    break;
                }
                j++; k++;
            }
            if (j == w2.size() && w1.size() > w2.size())
                return "";
        }

        queue<char> q;
        for (auto &[c, deg] : indegree)
            if (deg == 0) q.push(c);

        string ans = "";
        while (!q.empty()) {
            char node = q.front(); q.pop();
            ans += node;
            for (char nxt : adj[node]) {
                indegree[nxt]--;
                if (indegree[nxt] == 0)
                    q.push(nxt);
            }
        }

        return ans.size() == indegree.size() ? ans : "";
    }
};
