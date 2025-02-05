/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void traversal(TreeNode* root, vector<int>& ans) {
        if (root) {
            ans.push_back(root->val);
            if (root->left)
                traversal(root->left, ans);
            if (root->right)
                traversal(root->right, ans);
        }
        return;
    }
    //iterative approach
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        //if (root == NULL)
          //  return {};
        //traversal(root, ans);
    //Iterative approach
    if(root==NULL)return ans;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty() ){
        root=st.top();
        st.pop();
        ans.push_back(root->val);
        if(root->right) st.push(root->right);
        if(root->left) st.push(root->left);
    }
        return ans;
    }
};