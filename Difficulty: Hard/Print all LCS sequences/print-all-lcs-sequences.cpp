//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    set<string> ans;
    int lcs;
    vector<vector<int>> dp;

    int getLCS(string& s, string& t, int i, int j) {
        if (i >= s.length() || j >= t.length()) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j]) return dp[i][j] = 1 + getLCS(s, t, i + 1, j + 1);
        return dp[i][j] = max(getLCS(s, t, i + 1, j), getLCS(s, t, i, j + 1));
    }

    void solve(string& s, string& t, int i, int j, string s1) {
        if (s1.length() == lcs) {
            ans.insert(s1);
            return;
        }
        if (i >= s.length() || j >= t.length()) return;

        for (char c = 'a'; c <= 'z'; c++) {
            bool flag = false;
            for (int x = i; x < s.length(); x++) {
                if (s[x] == c) {
                    for (int y = j; y < t.length(); y++) {
                        if (t[y] == c && getLCS(s, t, x + 1, y + 1) == lcs - s1.length() - 1) {
                            solve(s, t, x + 1, y + 1, s1 + c);
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag) break;
            }
        }
    }

public:
    vector<string> all_longest_common_subsequences(string s, string t) {
        ans.clear(); 
        dp = vector<vector<int>>(s.length(), vector<int>(t.length(), -1));
        lcs = getLCS(s, t, 0, 0);
        solve(s, t, 0, 0, "");
        return vector<string>(ans.begin(), ans.end());
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends