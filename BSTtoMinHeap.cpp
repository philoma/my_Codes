#include <bits/stdc++.h>
void inorder(BinaryTreeNode* root,vector<int> &ans)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
void convertInToPre(BinaryTreeNode* root,vector<int> &arr,int &i)
{
    if(root==NULL)
        return;
    root->data = arr[i++];
    convert(root->left,arr,i);
    convert(root->right,arr,i);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    vector<int> ans;
    inorder(root,ans);
    
    
    int i = 0;
     convertInToPre(root,ans,i);
    return root;
    // Write your code here.
}
