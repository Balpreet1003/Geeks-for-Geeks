//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        vector<int>prev(W+1,0);
        vector<int>curr(W+1,0);
        for(int i=n-1;i>=0;i--){
            for(int w=0;w<=W;w++){
                int exc=prev[w];
                int inc=0;
                if(wt[i]<=w)inc=curr[w-wt[i]]+val[i];
                curr[w]=max(inc,exc);
            }
            prev=curr;
        }
        return curr[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends