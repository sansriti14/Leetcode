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
    void findSmallest(TreeNode* node, string curr_str, string& smallest_str) {
        if (node == NULL) return;
        
        if (!node->left && !node->right) {
            smallest_str = min(smallest_str, char(node->val + 'a') + curr_str);
        }
        
        findSmallest(node->left, char(node->val + 'a') + curr_str, smallest_str);
        findSmallest(node->right, char(node->val + 'a') + curr_str, smallest_str);
    }
    
public:
    string smallestFromLeaf(TreeNode* root) {
        string curr_str = "", smallest_str = "~";
        
        findSmallest(root, curr_str, smallest_str);
        
        return smallest_str;
    }
};