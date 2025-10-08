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
    void helper(TreeNode *node, int k,int &cnt,int &kthsmallest){
        //base case 
        if(node==NULL)return;
        //for smallest element check the left subtree 
        helper(node->left,k,cnt,kthsmallest);
        cnt++;
        if(cnt==k){
            kthsmallest=node->val;
            return;
        }
        //if not found in the left subtree check the right subtree
        helper(node->right,k,cnt,kthsmallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        int kthsmallest=INT_MAX;
        int cnt=0;
        helper(root,k,cnt,kthsmallest);
        return kthsmallest;
    }
};