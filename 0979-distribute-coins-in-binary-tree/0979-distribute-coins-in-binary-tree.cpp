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
    int findMinMoves(TreeNode* node, int &ans){
        if (node == NULL) return 0;
        
        if(!node->left && !node->right){
            return node->val - 1;
        }

        int left = findMinMoves(node->left, ans);
        int right = findMinMoves(node->right, ans);

        ans += abs(left) + abs(right);
        int curr_val = (node->val - 1) + left + right;

        return curr_val;
    }    
    
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        findMinMoves(root, ans);
        return ans;
    }
};