// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        stack<string>st;
        for(char c:exp){
            if(isalpha(c)){
                st.push(string(1, c));
            }
            else{
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                st.push("("+s2+string(1,c)+s1+")");
            }
        }
        return st.top();
    }
};