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
    int index = 0;
    
    bool dfs(TreeNode* node, vector<int>& voyage, vector<int>& ans) {
        if(node == NULL) return true;
        
        if(node->val != voyage[index++]) return false;
        
        if(node->left && (node->left->val != voyage[index])) {
            ans.push_back(node->val);
            return dfs(node->right, voyage, ans) && dfs(node->left, voyage, ans);
        }
        
        return dfs(node->left, voyage, ans) && dfs(node->right, voyage, ans);
    }
    
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        return dfs(root, voyage, ans) ? ans : vector<int>{-1};
    }
};