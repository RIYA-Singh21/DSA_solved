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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        //initialize the flag
        bool flag=true; //or 1 if flag==true then move LtoR else move RtoL
        while(!q.empty()){
            int size=q.size();
            vector<int>elements(size);
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();
                int index=(flag)?i:(size-1-i);
                elements[index]=node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
            }
            flag=!flag;
            ans.push_back(elements);
        }
        return ans;
    }
};