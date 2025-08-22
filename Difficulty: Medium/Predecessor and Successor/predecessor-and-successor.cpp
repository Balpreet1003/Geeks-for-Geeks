/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
    Node* get_successor(Node* root, int key){
        Node* ans=NULL, *curr=root;
        while(curr){
            if(curr->data<=key)
                curr=curr->right;
            else{
                ans=curr;
                curr=curr->left;
            }
        }
        return ans;
    }
    Node* get_predecessor(Node* root, int key){
        Node* ans=NULL, *curr=root;
        while(curr){
            if(curr->data>=key)
                curr=curr->left;
            else{
                ans=curr;
                curr=curr->right;
            }
        }
        return ans;
    }
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node* >ans(2,NULL);
        ans[0]=get_predecessor(root, key);
        ans[1]=get_successor(root, key);
        return ans;
    }
};