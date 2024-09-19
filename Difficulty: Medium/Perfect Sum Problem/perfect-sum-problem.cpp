//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    const int mod=1000000007;
	public:
	int perfectSum(int a[], int n, int sum){
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
	    dp[n][0]=1;
	    for(int i=n-1;i>=0;i--){
	        for(int k=0;k<=sum;k++){
	            if(k>=a[i])dp[i][k]=(dp[i][k]+dp[i+1][k-a[i]])%mod;
	            dp[i][k]=(dp[i][k]+dp[i+1][k])%mod;
	        }
	    }
        return dp[0][sum]%mod;
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends