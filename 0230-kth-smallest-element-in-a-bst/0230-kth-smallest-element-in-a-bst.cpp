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
//using iterative inorder apporoach
TreeNode*helper(TreeNode*root,int k,int &count){
    if(root==NULL)return NULL;
    TreeNode*left=helper(root->left,k,count);
    if(left!=NULL)return left;
    count++;
    if(count==k)return root;
    return helper(root->right,k,count);

}

    int kthSmallest(TreeNode* root, int k) {
    int count=0;
      TreeNode* result=helper(root,k,count);
      return result?result->val:0;
    }
};