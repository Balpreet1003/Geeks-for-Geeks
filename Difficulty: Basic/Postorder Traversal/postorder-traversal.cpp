/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */
class Solution {
    vector<int>ans;
    void get_postOrder(Node* root){
        if(!root){
            return;
        }
        get_postOrder(root->left);
        get_postOrder(root->right);
        ans.push_back(root->data);
    }
  public:
    // Function to return a list containing the postorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        get_postOrder(root);
        return ans;
    }
};