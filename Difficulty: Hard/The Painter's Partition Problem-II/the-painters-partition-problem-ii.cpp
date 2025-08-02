class Solution {
    bool is_possible(vector<int>&arr, int time, int painters){
        int cnt=1, sum=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>time){
                return false;
            }
            if(sum+arr[i]<=time){
                sum+=arr[i];
            }
            else{
                cnt++;
                sum=arr[i];
            }
        }
        return cnt<=painters;
    }
  public:
    int minTime(vector<int>& arr, int k) {
        int i=0, j=accumulate(arr.begin(), arr.end(),0);
        int ans=0;
        while(i<=j){
            int mid=j-((j-i)/2);
            if(is_possible(arr, mid, k)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};