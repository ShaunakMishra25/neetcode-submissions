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
    boolean hBalanced = true;

    private int height (TreeNode node) {
        if(node == null) return 0;

        int left = height(node.left);
        int right = height(node.right);

        if(Math.abs(left - right) > 1) {
            hBalanced = false;
        }
        return 1 + Math.max(left, right);
    }
    public boolean isBalanced(TreeNode root) {
        height(root);
        return hBalanced;
    }
}
