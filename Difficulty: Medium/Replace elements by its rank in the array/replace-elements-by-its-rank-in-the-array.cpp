//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> replaceWithRank(vector<int> &a, int n){
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<a.size();i++){
            if(m.find(a[i])==m.end()){
                pq.push(a[i]);
                m[a[i]].push_back(i);
            }
            else m[a[i]].push_back(i);
        }
        int i=1;
        vector<int>ans(a.size());
        while(!pq.empty()){
            int x=pq.top();
            pq.pop();
            for(int j=0;j<m[x].size();j++){
                ans[m[x][j]]=i;
            }
            i++;
        }
        return ans;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends