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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, 0});
        
        int max_width = 0;
        while(!bfs.empty()) {
            int size = bfs.size();
            int min_index_at_level = bfs.front().second;
            
            int first_index, last_index;
            for(int i = 0; i < size; i++) {
                TreeNode* node = bfs.front().first;
                long long curr_index = bfs.front().second - min_index_at_level;
                bfs.pop();
                
                if(i == 0) first_index = curr_index;
                if(i == size-1) last_index = curr_index;
                
                if(node->left)
                    bfs.push({node->left, 2 * curr_index + 1});
                if(node->right)
                    bfs.push({node->right, 2 * curr_index + 2});
            }
            
            max_width = max(max_width, last_index - first_index + 1);
        }
        return max_width;
    }
};