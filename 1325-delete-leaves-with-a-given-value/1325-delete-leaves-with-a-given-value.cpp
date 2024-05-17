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
private:
    bool isLeaf(TreeNode* node) {
        return (!node->left && !node->right);
    }
    
    TreeNode* solve(TreeNode* node, int target) {
        if (node == NULL) return NULL;
        
        node->left = solve(node->left, target);
        node->right = solve(node->right, target);
        
        return (node->left == node->right && node->val == target) ? NULL : node;
    }
    
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root, target);
    }
};
