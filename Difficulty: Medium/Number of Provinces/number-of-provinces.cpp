//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> a, int V) {
        unordered_map<int,vector<int>>adjList;
        int n=a.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                queue<int>q;
                q.push(i);
                visited[q.front()]=1;
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(auto j:adjList[x]){
                        if(!visited[j]){
                            q.push(j);
                            visited[j]=1;
                        }
                    }
                }
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends