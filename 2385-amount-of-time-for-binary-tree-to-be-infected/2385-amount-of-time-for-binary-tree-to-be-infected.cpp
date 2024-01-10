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
    void findStartingNode(TreeNode* node, int start, TreeNode* &starting_node) {
        if(node == NULL) return;
        
        if(node->val == start) {
            starting_node = node;
            return;
        }
        
        findStartingNode(node->left, start, starting_node);
        findStartingNode(node->right, start, starting_node);
    }
    
    void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& child_to_parent) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        
        while(!bfs.empty()) {
            int size = bfs.size();
            
            for(int i = 0; i < size; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();
                
                if(node->left) {
                    bfs.push(node->left);
                    child_to_parent[node->left] = node;
                }
                
                if(node->right) {
                    bfs.push(node->right);
                    child_to_parent[node->right] = node;
                }
            }
        }
    }  
    
public:
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* starting_node;
        findStartingNode(root, start, starting_node);
        
        unordered_map<TreeNode*, TreeNode*> child_to_parent;
        findParent(root, child_to_parent);
        
        int time = -1;
        queue<TreeNode*> bfs;
        bfs.push(starting_node);
        
        unordered_map<TreeNode*, bool> visited;
        visited[starting_node] = true;
        
        while(!bfs.empty()) {
            int size = bfs.size();
            for(int i = 0 ; i < size; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();
                
                if(node->left && visited.find(node->left) == visited.end()) {
                    bfs.push(node->left);
                    visited[node->left] = true;
                }
                
                if(node->right && visited.find(node->right) == visited.end()) {
                    bfs.push(node->right);
                    visited[node->right] = true;
                }
                
                if(node != root && visited[child_to_parent[node]] == false) {
                    bfs.push(child_to_parent[node]);
                    visited[child_to_parent[node]] = true;
                }
            }
            
            time++;
        }
        
        return time;
    }
};