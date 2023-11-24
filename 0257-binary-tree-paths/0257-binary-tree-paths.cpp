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
        return (node->left == NULL && node->right == NULL);
    }
    
    void findPaths(TreeNode* node, string temp, vector<string>& paths) {
        if(isLeaf(node)) {
            paths.push_back(temp);
            return;
        }
        
        if(node->left) 
            findPaths(node->left, temp + "->" + to_string(node->left->val), paths);
        if(node->right) 
            findPaths(node->right, temp + "->" + to_string(node->right->val), paths);
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(root == NULL) return paths;
        
        string temp = to_string(root->val);
        findPaths(root, temp, paths);
        return paths;
    }
};