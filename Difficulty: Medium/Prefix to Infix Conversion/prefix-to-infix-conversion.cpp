// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) {
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
};