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
    
    void dfs(TreeNode* node, string& str) {
        if(node == NULL) return;
        
        if(isLeaf(node))
            str += (to_string(node->val) + "#");
        
        dfs(node->left, str);
        dfs(node->right, str);
    }
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string leaf_seq1 = "", leaf_seq2 = "";
        dfs(root1, leaf_seq1);
        dfs(root2, leaf_seq2);
        
        return leaf_seq1 == leaf_seq2;
    }
};