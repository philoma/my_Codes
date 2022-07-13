class Solution {
    int path(TreeNode*root, int &s){
        if(root==NULL) return 0;
        int ls=max(0,path(root->left,s));
        int rs=max(0,path(root->right,s));
        s=max(s,ls+rs+root->val); 
        return max(ls,rs)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        
        int s=INT_MIN;
        path(root,s);
        return s;
        
    }
};
