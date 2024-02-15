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
    int pre_index = 0, post_index = 0;
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[pre_index++]);
        
        if(root->val != postorder[post_index]) {
            root->left = constructFromPrePost(preorder, postorder);
        }
        
        if(root->val != postorder[post_index]) {
            root->right = constructFromPrePost(preorder, postorder);
        }
        
        post_index++;
        
        return root;
    }
};