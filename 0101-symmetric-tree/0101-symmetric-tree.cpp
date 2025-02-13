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
    bool checksymmetry(TreeNode*right,TreeNode*left){
         if(right==NULL || left==NULL )
            return(right==left);
        if(right->val !=left->val)return false;
        return checksymmetry(right->left,left->right) && checksymmetry(right->right,left->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root==NULL || checksymmetry(root->right,root->left);
    }
};