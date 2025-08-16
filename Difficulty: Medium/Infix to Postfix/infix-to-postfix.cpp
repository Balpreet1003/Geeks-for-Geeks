class Solution {
    int priority(char& c){
        if(c=='^')return 3;
        if(c=='*' || c=='/')return 2;
        if(c=='+' || c=='-')return 1;
        return -1;
    }
  public:
    string infixToPostfix(string& s) {
        stack<char>st;
        string ans="";
        for(char c:s){
            if(c=='('){
                st.push(c);
            }
            else if(isalnum(c)){
                ans+=c;
            }
            else if(c==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                if(st.top()=='('){
                    st.pop();
                }
            }
            else{
                while(!st.empty() && priority(c)<=priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()){
            if(st.top()!='('){
                ans+=st.top();
            }
            st.pop();
        }
        return ans;
    }
};
