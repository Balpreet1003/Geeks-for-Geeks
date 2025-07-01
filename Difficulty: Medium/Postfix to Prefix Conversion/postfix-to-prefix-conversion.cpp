// User function Template for C++
class Solution {
  public:
    string postToPre(string post_exp) {
        stack<string> st;

        for (char c : post_exp) {
            if (isalpha(c)) {
                st.push(string(1, c)); // push the operand
            } else {
                // It's an operator
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();
                string temp = c + op1 + op2; // prefix format
                st.push(temp);
            }
        }

        return st.top(); // final prefix expression
    }
};