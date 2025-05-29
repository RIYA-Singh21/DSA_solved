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
    //use traversals ex.here i m using inorder
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p==null || q==null)
            return (p==q);
        return isSameTree(p.left,q.left) && (p.val==q.val) && isSameTree(p.right,q.right);
    }
}