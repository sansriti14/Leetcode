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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, vector<pair<int, int>>> mp;
        unordered_set<int> isChild;
        
        for (auto it: descriptions) {
            isChild.insert(it[1]);
            
            mp[it[0]].push_back({it[1], it[2]});
        }
        
        int rootVal;
        for (auto it: mp) {
            if (isChild.find(it.first) == isChild.end()) {
                rootVal = it.first;
            }
        }
        
        TreeNode* root = new TreeNode(rootVal);
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            for (auto it: mp[node->val]) {
                if (it.second == 1) {
                    TreeNode* leftChild = new TreeNode(it.first);
                    node->left = leftChild;
                    
                    if (mp.find(it.first) != mp.end()) {
                    q.push(leftChild);
                    }
                }
                
                else {
                    TreeNode* rightChild = new TreeNode(it.first);
                    node->right = rightChild;
                    
                    if (mp.find(it.first) != mp.end()) {
                    q.push(rightChild);
                    }
                }
                
            }
        }
        
        return root;
    }
};