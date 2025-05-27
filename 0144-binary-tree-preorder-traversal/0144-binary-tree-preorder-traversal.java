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
//iterative approach
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer>pre=new ArrayList<>();
        if(root==null)return pre;
        Stack<TreeNode>stk=new Stack<>();
        stk.push(root);
        while(!stk.isEmpty()){
            root=stk.pop();
            pre.add(root.val);
            if(root.right!=null)
                stk.push(root.right);
            if(root.left!=null)
                stk.push(root.left); 
        }
        return pre;
    }
}