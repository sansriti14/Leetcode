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
    void findKthSmallest(TreeNode* node, int& k, int& ans) {
        if (node == NULL) return;
        
        findKthSmallest(node->left, k, ans);
        k--;
        
        if (k == 0) {
            ans = node->val;
            return;
        }
        
        findKthSmallest(node->right, k, ans);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        
        findKthSmallest(root, k, ans);
        return ans;
    }
};