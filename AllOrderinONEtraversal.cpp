
// All order traversals in one traversal
class Solution
{
public:
    vector<int> allorder(TreeNode *root)
    {
        stack<pair<TreeNode*,int>>st;
        st.push({root,1});
        vector<int>pre,in,post;
        if(root==NULL) return;

        while(!st.empty()){
            auto it=st.top();
            st.pop();
            //part of preorder
            //increment num 1 to 2
            //push left side of tree
            if(it.second==1){
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->left!=NULL){
                st.push(it.first->left,1);
                }

            }

            //part of inorder
            //increment num from 2 to 3
            //push right 
            else if(it.second==2){
                in.push_back(it.first->val);
                it.second++;


                if(it.first->right!=NULL){
                st.push(it.first->right,1);
                }

            }

            //dont push it back again 
            else{
                posy.push_back(it.first->val);
            }
        }

    }
};