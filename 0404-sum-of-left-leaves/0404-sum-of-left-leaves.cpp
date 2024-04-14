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
    int findSumOfLeftLeaves(TreeNode* node, bool flag) {
        if (node == NULL) return 0;
        if (!node->left && !node->right && flag) return node->val;
        
        int leftSum = findSumOfLeftLeaves(node->left, true);
        int rightSum = findSumOfLeftLeaves(node->right, false);
        
        return leftSum + rightSum;
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return findSumOfLeftLeaves(root, false);
    }
};