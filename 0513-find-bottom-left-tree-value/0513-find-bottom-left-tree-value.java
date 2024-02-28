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
    int bottomLeftValue;
    int maxDepth;
    
    private void findLeftmost(TreeNode node, int level) {
        if(node == null) return;
        
        if(level > maxDepth) {
            bottomLeftValue = node.val;
            maxDepth = level;
        }
        
        findLeftmost(node.left, level + 1);
        findLeftmost(node.right, level + 1);
    }
    
    public int findBottomLeftValue(TreeNode root) {
        bottomLeftValue = root.val;
        
        maxDepth = 0;
        findLeftmost(root, 0);
        
        return bottomLeftValue;
    }
}