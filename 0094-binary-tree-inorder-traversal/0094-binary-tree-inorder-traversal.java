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
    //iterative traversal
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer>inorder=new ArrayList<>();
        if(root==null)return inorder;
        Stack<TreeNode>stk=new Stack<>();
        
    while(root!=null || !stk.isEmpty()){
        if(root!=null){
            stk.add(root);
            root=root.left;
        }else{
                root=stk.pop();
                inorder.add(root.val);
                root=root.right;
            
        }
    }
    return inorder;
    }
}