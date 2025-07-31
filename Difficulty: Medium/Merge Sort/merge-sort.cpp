class Solution {
    void merge_arr(vector<int>&arr,int l, int r, int mid){
        int n1=mid-l+1;
        int n2=r-mid;
        vector<int>left(n1),right(n2);
        for(int i=0;i<n1;i++){
            left[i]=arr[i+l];
        }
        for(int i=0;i<n2;i++){
            right[i]=arr[mid+i+1];
        }
        int i=0,j=0,k=l;
        while(i<n1 && j<n2){
            if(left[i]<right[j]){
                arr[k]=left[i++];
            }
            else{
                arr[k]=right[j++];
            }
            k++;
        }
        while(i<n1){
            arr[k++]=left[i++];
        }
        while(j<n2){
            arr[k++]=right[j++];
        }
    }
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l>=r){
            return;
        }
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge_arr(arr,l,r,mid);
    }
};