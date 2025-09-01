class Solution {
    vector<int>dp;
    int solve(string& s, int i){
        if(i>s.length() || s[i]=='0')
            return 0;
        if(i>=s.length()-1)
            return 1;
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=solve(s, i+1);
        if(((s[i]-'0')*10 +(s[i+1]-'0'))<=26){
            ans+=solve(s, i+2);
        }
        return dp[i]=ans;
    }
  public:
    int countWays(string &digits) {
        // for(int i=0;i<digits.length();i++){
        //     if(digits[i]=='0')
        //         return 0;
        // }
        // Code here
        dp.resize(digits.length(),-1);
        return solve(digits, 0);
    }
};