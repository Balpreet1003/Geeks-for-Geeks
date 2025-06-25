// User function Template for C++

class Solution {
    vector<int>ans;
    void cnt(int& n,int&x){
        while(n>=x){
            n-=x;
            ans.push_back(x);
        }
    }
  public:
    vector<int> minPartition(int n) {
        vector<int>nums={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        for(int i=9;i>=0;i--){
            cnt(n,nums[i]);
        }
        return ans;
    }
};