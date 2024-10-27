//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++



class Solution {
    vector<string>ans;
    int n,m;
    void solve(vector<vector<int>>&a,int i,int j,string s,vector<vector<bool>>&visited){
        if(i<0 || i>=n || j<0 || j>=m || a[i][j]==0 || visited[i][j])return ;
        if(i==n-1 && j==m-1){
            ans.push_back(s);
            return;
        }
        visited[i][j]=true;
        solve(a,i+1,j,s+'D',visited);
        solve(a,i-1,j,s+'U',visited);
        solve(a,i,j+1,s+'R',visited);
        solve(a,i,j-1,s+'L',visited);
        visited[i][j]=false;
    }
  public:
    vector<string> findPath(vector<vector<int>> &a) {
        n=a.size(),m=a[0].size();
        if(a[0][0]==0 || a[n-1][m-1]==0)return {};
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        solve(a,0,0,"",visited);
        return ans;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends