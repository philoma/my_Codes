class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ds;
    bool flag =1;
    if(root==NULL) return ds;
    queue<TreeNode*>q;
    
    q.push(root);
    while(!q.empty()){
       vector<int>level;
        int size=q.size();
        for(int i=0;i<size;i++){
            
          TreeNode *node=q.front();
        q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            
        }
        if(!flag)
            reverse(level.begin(),level.end());
      
            ds.push_back(level);
        
        flag=!flag;
        
    }
    return ds;
        
    }
};
