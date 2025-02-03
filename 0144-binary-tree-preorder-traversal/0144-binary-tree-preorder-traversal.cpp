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
    void traversal(TreeNode*root,vector<int>&ans){
        if(root){
            ans.push_back(root->val);
            if(root->left)
                traversal(root->left,ans);
            if(root->right)
                traversal(root->right,ans);
        }
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return {} ;
        traversal(root,ans);
        return ans;
        
        
    }
};