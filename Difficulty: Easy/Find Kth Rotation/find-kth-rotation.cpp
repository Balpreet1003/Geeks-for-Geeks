class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        if(arr.size()==1){
            return 0;
        }
        int i=0,j=arr.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]<arr[j]){
                j=mid;
            }
            else{
                i=mid+1;
            }
        }
        return j;
    }
};
