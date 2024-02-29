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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int curr_level = 0;
        
        while(!q.empty()) {
            int size = q.size();
            
            int prev_value = -1;
            
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                
                if((curr_level % 2) == (node->val % 2)) return false;
                
                if((curr_level % 2 == 1) && (prev_value != -1 && node->val >= prev_value)) return false;
                
                if((curr_level % 2 == 0) && (prev_value != -1 && node->val <= prev_value)) return false;
                
                prev_value = node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            curr_level++;
        }
        
        return true;
    }
};