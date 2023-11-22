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
public:
    int ans = 0;
    
    int findSum(TreeNode* node, int& count) {
        if(node == NULL) return 0;
        count++;
        
        int left = findSum(node->left, count);
        int right = findSum(node->right, count);
        
        return (node->val + left + right);
    }
    
    void solve(TreeNode* node) {
        if(node == NULL) return;
        int count = 0;
        int average = (findSum(node, count))/count;
        
        if(average == node->val) ans++;
        
        solve(node->left);
        solve(node->right);
    }
    
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};