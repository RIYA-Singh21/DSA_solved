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
private: //member variables
    TreeNode*prev;
    TreeNode*first;
    TreeNode*middle;
    TreeNode*last;

public:
    void inorder(TreeNode *root){
        if(root==NULL)return;

        inorder(root->left);
        
        if( prev &&(root->val<prev->val) ){
            //for the first violation
            if(first==NULL){
                first=prev;
                middle=root;
            }//2ns violation
            else last=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);
    }
};