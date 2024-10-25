//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &a) {
        int n = a.size();
    
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != 0 && a[i] == a[i + 1]) {
                a[i] = 2 * a[i]; 
                a[i + 1] = 0; 
            }
        }
    
        vector<int> ans(n, 0); 
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                ans[index++] = a[i];
            }
        }
    
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends