// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        stack<string>st;
        for(char c:post_exp){
            if(isalpha(c)){
                st.push(string(1,c));
            }
            else{
                string s1=st.top(); st.pop();
                string s2=st.top(); st.pop();
                string s=c+s2+s1;
                st.push(s);
            }
        }
        return st.top();
    }
};