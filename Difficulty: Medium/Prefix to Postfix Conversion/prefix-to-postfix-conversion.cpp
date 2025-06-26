// User function Template for C++

class Solution {
    string per_to_in(string&s){
        int n = s.length();
        stack<string> st;

        for (int i = n - 1; i >= 0; i--) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                string operand(1, s[i]);
                st.push(operand);
            } 
            else {
                // Operator case
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string expr = "(" + op1 + s[i] + op2 + ")";
                st.push(expr);
            }
        }

        return st.top();
    }
  public:
    string preToPost(string s) {
        string s1=per_to_in(s);
        stack<char>st;
        string ans="";
        for(char c:s1){
            if(c=='(')continue;
            else if(c==')'){
                ans+=st.top();
                st.pop();
            }
            else if(isalpha(c)){
                ans+=c;
            }
            else{
                st.push(c);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};