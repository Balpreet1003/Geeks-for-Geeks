class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int i=0,j=arr.size()-1, ans=arr.size();
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]>=target){
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
