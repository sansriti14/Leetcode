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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode; 
        }
        
        queue<TreeNode*> q; 
        q.push(root);
        
        int currDepth = 0; 
        
        while(!q.empty()) {
            int n = q.size(); 
            
            currDepth++; 
            
            while(n--) {
                TreeNode* currNode = q.front(); 
                q.pop(); 
                
                if(currDepth != depth - 1) {
                    if(currNode->left) q.push(currNode->left);
                    if(currNode->right) q.push(currNode->right);
                }
                
                else {
                    TreeNode* newNode1 = new TreeNode(val);
                    newNode1->left = currNode->left;
                    currNode->left = newNode1;
                    
                    TreeNode* newNode2 = new TreeNode(val);
                    newNode2->right = currNode->right;
                    currNode->right = newNode2;
                }
            }
        }

        return root; 
    }
};