/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
    // vector -> {max_val, min_val, size}
    vector<int> solve(Node* root){
        if(!root){
            return {INT_MIN, INT_MAX, 0};
        }
        vector<int>left=solve(root->left);
        vector<int>right=solve(root->right);
        
        if(left[0]<root->data && right[1]>root->data){
            return {max(root->data, right[0]), min(root->data, left[1]), left[2]+right[2]+1};
        }
        return {INT_MAX, INT_MIN, max(left[2], right[2])};
    }
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        return solve(root)[2];
    }
};