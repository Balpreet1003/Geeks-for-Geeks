class Solution {
  public:
    int celebrity(vector<vector<int> >& nums) {
        int n=nums.size();
        int t=0,d=n-1;
        while(t<d){
            if(nums[t][d]==1){
                t++;
            }
            else{
                d--;
            }
        }
        bool flag=true;
        for(int i=0;i<n;i++){
            if(i!=t){
                if(nums[i][t]==0){
                    flag=false;
                    break;
                }
            }
        }
        if(!flag){
            return -1;
        }
        for(int i=0;i<n;i++){
            if(i!=t){
                if(nums[t][i]==1){
                    flag=false;
                    break;
                }
            }
        }
        return flag ? t : -1;
    }
};