//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
    int bs(vector<pair<int,int>>& a, int t) {
        int i = 0, j = a.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid].first == t) return a[mid].second;
            if (a[mid].first > t) j = mid - 1;
            else i = mid + 1;
        }
        return -1;
    }
public:
    vector<vector<int>> findTriplets(vector<int>& a) {
        set<vector<int>> ans;
        int n = a.size();
        vector<pair<int, int>> b;
        for (int i = 0; i < n; i++)
            b.push_back({a[i], i});
        sort(b.begin(), b.end());
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = bs(b, -(b[i].first + b[j].first));
                if (x != -1 && x != b[i].second && x != b[j].second) {
                    vector<int> temp = {b[i].second, b[j].second, x};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
            }
        }
        
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends