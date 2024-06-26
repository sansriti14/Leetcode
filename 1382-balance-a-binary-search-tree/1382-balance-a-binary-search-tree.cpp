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
    void findInorder(TreeNode* root, vector<int> &inorder) {
        if (root == NULL) return;
        
        findInorder(root->left, inorder);
        inorder.push_back(root->val);
        findInorder(root->right, inorder);
    }
    
    TreeNode* createBST(vector<int> &inorder, int start, int end) {
        if(start > end) return NULL;
        
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        
        root->left = createBST(inorder, start, mid - 1);
        root->right = createBST(inorder, mid + 1, end);
        
        return root;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        findInorder(root, inorder);
        
        return createBST(inorder, 0, inorder.size() - 1);
    }
};