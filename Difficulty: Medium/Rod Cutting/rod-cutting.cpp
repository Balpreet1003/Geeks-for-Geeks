//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    int solve(int p[],int n,int i,int l,vector<vector<int>>&dp){
        if(l<=0 || i>n)return 0;
        if(dp[i][l]!=-1)return dp[i][l];
        int exc=solve(p,n,i+1,l,dp);
        int inc=0;
        if(l>=i)inc=solve(p,n,i,l-i,dp)+p[i-1];
        return dp[i][l]=max(inc,exc);
    }
  public:
    int cutRod(int p[], int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(p,n,1,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends