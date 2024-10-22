//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    long long power(int base, int exp) {
        long long result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
            if (result > 1e9) return result; // Early termination if result exceeds m
        }
        return result;
    }
  public:
    int NthRoot(int n, int m) {
        int low = 1, high = m;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long midPow = power(mid, n);
            
            if (midPow == m) return mid;
            if (midPow < m) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends