//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    const int mod=1000000007;
    // int solve(vector<int>&a, int&d,int k,int i,vector<vector<int>>&dp){
    //     if(i==a.size() && k==0)return 1;
    //     if(i>=a.size() || k<0)return 0;
        
    //     if(dp[i][k]!=-1)return dp[i][k];
        
    //     return dp[i][k]=(solve(a,d,k-a[i],i+1,dp) + solve(a,d,k,i+1,dp))%mod;
    // }
  public:
    int countPartitions(int n, int d, vector<int>& a) {
        int sum=accumulate(a.begin(),a.end(),0);
        if(d>sum || (sum-d)%2!=0)return 0;
        int sum2=(sum-d)/2;
        vector<vector<int>>dp(n+1,vector<int>(sum2+1,0));
        dp[n][0]=1;
        for(int i=n-1;i>=0;i--){
            for(int k=0;k<=sum2;k++){
                if(k>=a[i]) dp[i][k]=(dp[i][k]+dp[i+1][k-a[i]])%mod;
                dp[i][k]=(dp[i][k]+dp[i+1][k])%mod;
            }
        }
        return dp[0][sum2];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends