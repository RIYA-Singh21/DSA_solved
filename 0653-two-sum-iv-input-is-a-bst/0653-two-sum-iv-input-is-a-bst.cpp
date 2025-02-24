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
class BSTIterator{
     stack<TreeNode*>stk;
    // reverse=true means go before 
    // reverse=false means go next
    bool reverse=true;
    public:
        BSTIterator(TreeNode* root, bool isReverse) {
        reverse=isReverse;
        pushall(root);
    }
    
    int next() {
        TreeNode * tempnode=stk.top();
        stk.pop();
        if(!reverse) pushall(tempnode->right);
        else pushall(tempnode->left);
        return tempnode->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
    private:
    void pushall(TreeNode* node){
        for(;node!=NULL;){
            stk.push(node);
            if(reverse==true){
                node=node->right;
            }else node=node->left;
        }  
    }
   

};

class Solution {
   
public:
     bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        BSTIterator l(root,false); // left means next
        BSTIterator r(root,true); //right means before

        int i=l.next();
        int j=r.next(); //this will act as r.before() since the cond is reversed in next func

        while(i<j){
            if(i+j==k)return true;
            if(i+j<k) i=l.next(); 
            else j=r.next(); 
        }
        return false;
    }


};