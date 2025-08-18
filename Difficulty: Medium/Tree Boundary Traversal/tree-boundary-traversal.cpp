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
    void get_left_vector(Node* root, vector<Node*>&a){
        if(!root)
            return;
        a.push_back(root);
        if(root->left)
            get_left_vector(root->left, a);
        else
            get_left_vector(root->right, a);
    }
    void get_leaf_vector(Node* root, vector<Node*>&a){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            a.push_back(root);
            return;
        }
        get_leaf_vector(root->left, a);
        get_leaf_vector(root->right, a);
    }
    void get_right_vector(Node* root, vector<Node*>&a){
        if(!root)
            return;
        a.push_back(root);
        if(root->right)
            get_right_vector(root->right, a);
        else
            get_right_vector(root->left, a);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<Node* >left, leaf, right;
        
        if(root->left)
            get_left_vector(root, left);
        else
            left.push_back(root);
        get_leaf_vector(root,leaf);
        get_right_vector(root->right, right);
        reverse(right.begin(), right.end());
        
        unordered_map<Node*, int>m;
        vector<int>ans;
        for(auto x:left){
            if(m.find(x)==m.end()){
                ans.push_back(x->data);
                m[x]=1;
            }
        }
        for(auto x:leaf){
            if(m.find(x)==m.end()){
                ans.push_back(x->data);
                m[x]=1;
            }
        }
        for(auto x:right){
            if(m.find(x)==m.end()){
                ans.push_back(x->data);
                m[x]=1;
            }
        }
        return ans;
    }
};