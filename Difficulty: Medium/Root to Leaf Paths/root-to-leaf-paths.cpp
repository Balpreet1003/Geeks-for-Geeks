/*

Definition for Binary Tree Node
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
    vector<vector<int>>ans;
    void solve(Node* root, vector<int>& temp){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            temp.push_back(root->data);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(root->data);
        solve(root->left, temp);
        solve(root->right, temp);
        temp.pop_back();
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<int>temp;
        solve(root, temp);
        return ans;
    }
};