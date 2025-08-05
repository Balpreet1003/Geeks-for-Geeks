// User function Template for C++

class Solution {
    set<string>ans;
    void solve(int num, string s, int cond){
        if(num==0){
            ans.insert(s);
            return;
        }
        if(cond==1){
            solve(num-1, s+"0",0);
        }
        else {
            solve(num-1, s+"1", 1);
            solve(num-1, s+"0", 0);
        }
    }
  public:
    vector<string> generateBinaryStrings(int num) {
        solve(num, "", 0);
        solve(num, "", 1);
        return vector<string>(ans.begin(), ans.end());
    }
};