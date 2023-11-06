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
    int findMaxPathSum(TreeNode* node, int& max_sum) {
        if(node == NULL) return 0;
        
        int leftSum = max(0, findMaxPathSum(node->left, max_sum));
        int rightSum = max(0, findMaxPathSum(node->right, max_sum));
        
        max_sum = max(max_sum, leftSum + rightSum + node->val);
        return (node->val) + max(leftSum, rightSum);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        findMaxPathSum(root, max_sum);
        return max_sum;
    }
};