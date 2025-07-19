/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */
class Solution {
  public:
    // Function to return a list containing the postorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        if(!root){
            return {};
        }
        vector<int>ans;
        stack<Node*>st1,st2;
        st1.push(root);
        Node* node;
        while(!st1.empty()){
            node=st1.top();
            st1.pop();
            st2.push(node);
            
            if(node->left){
                st1.push(node->left);
            }
            if(node->right){
                st1.push(node->right);
            }
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->data);
            st2.pop();
        }
        return ans;
    }
};