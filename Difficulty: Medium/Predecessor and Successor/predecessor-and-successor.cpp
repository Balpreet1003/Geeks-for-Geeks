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
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*>inorder;
        stack<Node*>st;
        Node* curr=root;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            inorder.push_back(curr);
            curr=curr->right;
        }
        vector<Node*>ans(2, NULL);
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]->data==key){
                if(i!=inorder.size()-1){
                    ans[1]=inorder[i+1];
                }
                break;
            }
            if(inorder[i]->data>key){
                if(i!=inorder.size()-1){
                    ans[1]=inorder[i];
                }
                break;
            }
            ans[0]=inorder[i];
        }
        return ans;
    }
};