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
    void traversal(TreeNode *root,vector<int>&ans){
        if(root==NULL) return;
        traversal(root->left,ans);
        ans.push_back(root->val);
        traversal(root->right,ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        //if(root==NULL)return {};
        vector<int>ans;
        //traversal(root,ans);
    //iterative approach
    if(root==NULL)return ans;
    TreeNode* node=root;
    stack<TreeNode*>st;
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else {
            if(st.empty()==true) break;
            node=st.top();
            st.pop();
            ans.push_back(node->val);
            node=node->right;
        }
    }
     
        return ans;
    }
};