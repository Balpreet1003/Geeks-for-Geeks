//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool isposs(vector<int>&a,int&k,int&mid){
        int c=0;
        int x=-1;
        for(int i:a){
            if(x==-1){
                c++;
                x=i;
            }
            else{
                if(i-x>=mid){
                    c++;
                    x=i;
                }
            }
        }
        return c>=k;
    }
public:
    int solve(int n, int k, vector<int> &a) {
        sort(a.begin(),a.end());
        int i=0,j=a[a.size()-1];
        int ans=-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(isposs(a,k,mid)){
                ans=mid;
                i=mid+1;
            }
            else j=mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends