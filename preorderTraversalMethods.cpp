//Recursive method

class Solution {
public:
    void preorder(TreeNode* root, vector<int>&v){
        if(root==NULL){
            return;
        }
        
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        preorder(root,v);
        return v;
    }
};


//link: https://leetcode.com/problems/binary-tree-preorder-traversal/

//Iterative method
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        stack<TreeNode*>s;
        s.push(root);
        vector<int>v;
        if(root==NULL) return v;
        while(!s.empty()){
            TreeNode*node=s.top();
            s.pop();
            if(node->right!=NULL)  s.push(node->right);
            if(node->left!=NULL)  s.push(node->left);
            v.push_back(node->val);

           
           
            
        }
        
        return v;
    }
};

