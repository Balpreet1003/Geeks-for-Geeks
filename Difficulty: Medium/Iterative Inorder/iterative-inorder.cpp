// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        vector<int>ans;
        stack<Node*>st;
        Node* node=root;
        while(node || !st.empty()){
            while(node){
                st.push(node);
                node=node->left;
            }
            node=st.top();
            st.pop();
            ans.push_back(node->data);
            node=node->right;
        }
        return ans;
    }
};