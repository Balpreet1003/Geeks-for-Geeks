/* A binary tree node has data, pointer to left child
   and a pointer to right child

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
  public:

    // Function to return a list containing the preorder traversal of the tree.
    vector<int> preorder(Node* root) {
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