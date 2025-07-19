/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    vector<int>ans;
    void get_inOrder(Node* root){
        if(!root){
            return ;
        }
        get_inOrder(root->left);
        ans.push_back(root->data);
        get_inOrder(root->right);
    }
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        get_inOrder(root);
        return ans;
    }
};