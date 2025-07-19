// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:

    // Function to return a list containing the preorder traversal of the tree.
    vector<int> preOrder(Node* root) {
        vector<int>ans;
        stack<Node*>st;
        Node* node = root;
        while(node || !st.empty()){
            while(node){
                ans.push_back(node->data);
                st.push(node);
                node=node->left;
            }
            node = st.top();
            st.pop();
            node=node->right;
        }
        return ans;
    }
};