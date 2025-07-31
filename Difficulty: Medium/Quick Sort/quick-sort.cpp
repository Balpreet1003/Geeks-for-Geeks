class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low>high){
            return;
        }
        int pivot=partition(arr,low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int j=low-1;
        for(int i=low; i<=high;i++){
            if(arr[i]<pivot){
                j++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[j+1],arr[high]);
        return j+1;
    }
};