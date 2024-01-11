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
    pair<int, int> dfs(TreeNode* root, int& max_value) {
        if (root == nullptr) {
            return {INT_MAX, INT_MIN};
        }

        auto left = dfs(root->left, max_value);
        auto right = dfs(root->right, max_value);

        int min_val = min(root->val, min(left.first, right.first));
        int max_val = max(root->val, max(left.second, right.second));

        max_value = max({max_value, abs(min_val - root->val), abs(max_val - root->val)});

        return {min_val, max_val};
    }    
    
public:
    int maxAncestorDiff(TreeNode* root) {
        int max_value = 0;
        dfs(root, max_value);
        return max_value;
    }
};
