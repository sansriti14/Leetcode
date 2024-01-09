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
    int sumEvenGrandparent(TreeNode* root) {
        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, -1});
        
        int sum = 0;
        
        while(!bfs.empty()) {
            int size = bfs.size();
            for(int i = 0; i < size; i++) {
                TreeNode* node = bfs.front().first;
                int parent = bfs.front().second;
                bfs.pop();
                
                if(node->left) {
                    if(parent % 2 == 0) sum += node->left->val;
                    bfs.push({node->left, node->val});
                } 
                
                if(node->right) {
                    if(parent % 2 == 0) sum += node->right->val;
                    bfs.push({node->right, node->val});
                } 
            }
        }
        
        return sum;
    }
};