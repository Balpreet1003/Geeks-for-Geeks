class Solution {
    private void swap(int[] arr, int i, int j)
    {
        if (i == j) return;
        
        arr[i]^=arr[j];
        arr[j]^=arr[i];
        arr[i]^=arr[j];
    }
    public void bubbleSort(int[] arr) {
        int n=arr.length;
        
        for(int i=0;i<n-1;i++)
        {
            boolean swapped=false;
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swap(arr, j, j+1);
                    swapped=true;
                }
            }
            if(!swapped)
            {
                break;
            }
        }
    }
}