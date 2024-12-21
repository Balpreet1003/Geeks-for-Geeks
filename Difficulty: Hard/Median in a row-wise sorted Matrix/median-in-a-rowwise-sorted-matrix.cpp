//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    int upperBound(vector<int>& arr, int tar) {
        int i = 0, j = arr.size() - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (arr[mid] <= tar) {
                i = mid + 1; // Move right
            } else {
                j = mid - 1; // Move left
            }
        }
        return i; // Returns the count of elements ≤ tar
    }

    int count(vector<vector<int>>& mat, int tar) {
        int ans = 0;
        for (int i = 0; i < mat.size(); i++) {
            ans += upperBound(mat[i], tar);
        }
        return ans;
    }

  public:
    int median(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int l = INT_MAX, r = INT_MIN;

        // Find global minimum and maximum in the matrix
        for (int i = 0; i < n; i++) {
            l = min(l, mat[i][0]);
            r = max(r, mat[i][m - 1]);
        }

        int req = (n * m) / 2; // Index of the median (0-based)
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int cnt = count(mat, mid);

            if (cnt <= req) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l; // l is the median
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends