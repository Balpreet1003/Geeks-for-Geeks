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
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int>ans;
        Node* curr=root;
        while(curr){
            if(!curr->left){
                ans.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(!prev->right){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    ans.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};