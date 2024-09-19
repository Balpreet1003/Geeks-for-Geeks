//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string s) {
        string ans="",temp="";
        for(char c:s){
            if(c=='.'){
                if(ans=="")ans=temp+ans;
                else ans=temp+"."+ans;
                temp="";
            }
            else{
                temp+=c;
            }
        }
        ans=temp+"."+ans;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends