//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &a, int k) {
        sort(a.begin(),a.end());
        int n=a.size();
        int mini=a[0]+k,maxi=a[n-1]-k;
        int ans=a[n-1]-a[0];
        int mi=0,ma=0;
        for(int i=0;i<n-1;i++){
            mi=min(mini,a[i+1]-k);
            ma=max(maxi,a[i]+k);
            if(mi<0)continue;
            
            ans=min(ans,ma-mi);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends