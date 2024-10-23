//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &a) {
        int ans=-1,x=0;
        for(int i=0;i<a.size();i++){
            int n=a[i].size();
            int j=0,k=n-1;
            int y=n;
            while(j<=k){
                int mid=(j+k)/2;
                if(a[i][mid]==1){
                    y=mid;
                    k=mid-1;
                }
                else j=mid+1;
            }
            if((n-y)>x){
                ans=i;
                x=n-y;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends