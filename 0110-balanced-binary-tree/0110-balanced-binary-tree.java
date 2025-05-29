/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    //logic is similar to finding the height of a bt 
    int check(TreeNode root){
        //check for null node
        if(root==null)return 0;
        int lheight=check(root.left);
        int rheight=check(root.right);
        //if lh || rh at any point are -1 ret -1
        if(lheight==-1 || rheight==-1)return -1;

        //at any pt diff left-right node >1 ret -1
        if(Math.abs(lheight-rheight)>1)return -1;
        
        return 1+Math.max(lheight,rheight);
    }
    public boolean isBalanced(TreeNode root) {
        if(check(root)==-1)return false;
        return true;
    }
}