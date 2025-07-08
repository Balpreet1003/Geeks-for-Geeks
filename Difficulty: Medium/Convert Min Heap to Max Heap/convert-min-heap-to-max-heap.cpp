// User function Template for C++

class Solution {
    void heapify(vector<int>& arr, int i,int& n){
        int l=2*i+1;
        int r=2*i+2;
        int maxi=i;
        if(l<n && arr[l]>arr[i]){
            maxi=l;
        }
        if(r<n && arr[r]>arr[maxi]){
            maxi=r;
        }
        if(maxi!=i){
            swap(arr[i],arr[maxi]);
            heapify(arr,maxi,n);
        }
    }
  public:
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        for(int i=(N-2)/2; i>=0;i--){
            heapify(arr,i,N);
        }
    }
};
