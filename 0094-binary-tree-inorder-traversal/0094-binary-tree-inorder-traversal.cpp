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
    void findInorder(TreeNode* node, vector<int>& inorder) {
        if(node == NULL) return;
        
        findInorder(node->left, inorder);
        inorder.push_back(node->val);
        findInorder(node->right, inorder);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        findInorder(root, inorder);
        return inorder;
    }
};