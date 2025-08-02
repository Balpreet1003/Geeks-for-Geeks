class Solution {
    bool is_possible(vector<int>& nums, int dis, int cows){
        int cnt=0, prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if((nums[i]-prev)>=dis){
                cnt++;
                prev=nums[i];
            }
        }
        return cnt>=(cows-1);
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        int i=0, j=*max_element(stalls.begin(),stalls.end());
        int ans=0;
        sort(stalls.begin(),stalls.end());
        while(i<=j){
            int mid=j-((j-i)/2);
            //cout<<mid<<endl;
            if(is_possible(stalls,mid,k)){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
            //cout<<ans<<endl;
        }
        return ans;
    }
};