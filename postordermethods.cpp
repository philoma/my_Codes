//recursive postorder
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void postorder(TreeNode*root, vector<int>&v){
        if(root==NULL){
            return;
        }
        postorder(root->left,v);
        postorder(root->right,v);
        v.push_back(root->val);
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        postorder(root,v);
        return v;
        
    }
};





//iterative using 2 stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>s1,s2;
        s1.push(root);
        if(root==NULL) return ans;
        while(!s1.empty()){
            TreeNode*node=s1.top();
            s1.pop();
            s2.push(node);
            
            if(node->left!=NULL){
                s1.push(node->left);
            }
             if(node->right!=NULL){
                s1.push(node->right);
            }
           
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};




//iterative using one stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>s;
       
        if(root==NULL) return ans;
        TreeNode* cur=root;
        while(cur!=NULL||!s.empty()){
            
            if(cur!=NULL){
                s.push(cur);
                cur=cur->left;
            }else{
                TreeNode*temp=s.top()->right;
                if(temp==NULL){
                    
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while(!s.empty()&& temp==s.top()->right){
                        temp=s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                    
                }else{
                    cur=temp;
                }
            }
            
        }
        return ans;
        
        
    }
};