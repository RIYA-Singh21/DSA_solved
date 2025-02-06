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
        traversal(root->right,ans);
        ans.push_back(root->val);
    }
    void traversaldoublestk(TreeNode *root,vector<int>&ans){
        stack<TreeNode*>st1,st2;
        st1.push(root);
        while(!st1.empty()){
            root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->left)
            st1.push(root->left);
            if(root->right)
            st1.push(root->right);
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
    }
    void singlestk(TreeNode*root,vector<int>&ans){
        stack<TreeNode*>st;
        TreeNode* curr=root;
        TreeNode*temp;
        while(curr!=NULL || !st.empty() ){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
                temp=(st.top())->right;
                if(temp==NULL){
                    temp=st.top();
                st.pop();
                ans.push_back(temp->val);
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
            }else{
                curr=temp;
            }
            }
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        vector<int>ans;
        //traversal(root,ans);
        //using 2 stacks
        //traversaldoublestk(root,ans);
        singlestk(root,ans);
        return ans;
    }
};