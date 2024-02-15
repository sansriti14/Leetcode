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
    int pre_index = 0, post_index = 0;
    
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        TreeNode root = new TreeNode(preorder[pre_index++]);
        
        if(root.val != postorder[post_index]) {
            root.left = constructFromPrePost(preorder, postorder);
        }
        
        if(root.val != postorder[post_index]) {
            root.right = constructFromPrePost(preorder, postorder);
        }
        
        post_index++;
        
        return root;
    }
}