//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int t, vector<int>& a, vector<int>& b) {
    int i = 0, j = 0, k = 0;
    
    while (i < a.size() && j < b.size()) {
        k++;
        if (a[i] < b[j]) {
            if (k == t) return a[i];
            i++;
        } else {
            if (k == t) return b[j];
            j++;
        }
    }
    
    while (i < a.size()) {
        k++;
        if (k == t) return a[i];
        i++;
    }
    
    while (j < b.size()) {
        k++;
        if (k == t) return b[j];
        j++;
    }
    
    return -1; 
}
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends