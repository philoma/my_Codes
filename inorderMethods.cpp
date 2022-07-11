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
// recursive
class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &v)
    {
        if (root != NULL)
        {
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }
        return;
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        inorder(root, v);
        return v;
    }

    // link: https://leetcode.com/problems/binary-tree-inorder-traversal/
};

// iterative:

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;

        vector<int> ans;

        TreeNode *node = root;

        while (true)
        {

            if (node != NULL)
            {
                s.push(node);
                node = node->left;
            }
            else
            {
                if (s.empty())
                    break;
                node = s.top();
                s.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};