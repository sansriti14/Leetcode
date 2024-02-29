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
            
            vector<int> level;
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                
                if((curr_level % 2) == (node->val % 2)) return false;
                
                if((curr_level % 2 == 1) && (level.size() > 0 && node->val >= level.back())) return false;
                
                if((curr_level % 2 == 0) && (level.size() > 0 && node->val <= level.back())) return false;
                
                level.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            curr_level++;
        }
        
        return true;
    }
};