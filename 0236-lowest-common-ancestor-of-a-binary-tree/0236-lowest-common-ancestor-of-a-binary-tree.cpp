/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)
            return root;
        //recursively check the left subtree and the right subtree
        TreeNode *left= lowestCommonAncestor(root->left, p,q);
        TreeNode *right= lowestCommonAncestor(root->right, p,q);

        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        //both the left and right return null means the current node is the answer 
        else 
            return root;

    }
};