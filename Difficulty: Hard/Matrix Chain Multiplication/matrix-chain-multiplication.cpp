class Solution {
    vector<vector<int>>dp;
public:
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        dp.resize(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i==j){
                    dp[i][j]=0;
                    continue;
                }
                int ans=INT_MAX;
                for(int k=i;k<j;k++){
                    ans=min(ans,arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n-1];
    }
};