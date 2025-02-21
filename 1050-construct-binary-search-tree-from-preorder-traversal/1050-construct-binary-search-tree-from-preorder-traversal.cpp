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
    TreeNode*construct(vector<int>&arr,int &i,int bound){
        if(i==arr.size() || arr[i]>bound)return NULL;
        TreeNode*root=new TreeNode(arr[i++]);
        root->left=construct(arr,i,root->val);
        root->right=construct(arr,i,bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0; // i is used to compare the initial node with it 
        return construct(preorder,i,INT_MAX);
        
    }
};