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
    int maxCount = INT_MIN;
    int currCount = 0;
    TreeNode* prev = NULL;
    vector<int> ans;
    
    void inorder(TreeNode* root, bool getlist) {
        if(root == NULL) return;
        
        inorder(root->left, getlist);
        
        if(prev && prev->val == root->val)
            currCount++;
        else
            currCount = 1;
        if(getlist == NULL) maxCount = max(maxCount, currCount);
        else if(currCount == maxCount) ans.push_back(root->val);
        prev = root;
        inorder(root->right, getlist);
    }
    
    vector<int> findMode(TreeNode* root) {
        ans.clear();
        if(root == NULL) return ans;

        inorder(root, false);

        prev = NULL;
        currCount = 0;
        inorder(root, true);
        
        return ans;
    }
};