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
    void findLeftmost(TreeNode* node, int& bottomLeftValue, int level, int& maxDepth) {
        if(node == NULL) return;
        
        if(level > maxDepth) {
            bottomLeftValue = node->val;
            maxDepth = level;
        }
        
        findLeftmost(node->left, bottomLeftValue, level + 1, maxDepth);
        findLeftmost(node->right, bottomLeftValue, level + 1, maxDepth);
    }
   
public:
    int findBottomLeftValue(TreeNode* root) {
        int bottomLeftValue = root->val;
        
        int maxDepth = 0;
        findLeftmost(root, bottomLeftValue, 0, maxDepth);
        
        return bottomLeftValue;
    }
};