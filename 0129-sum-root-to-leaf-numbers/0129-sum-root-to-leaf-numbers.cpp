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
    bool isLeaf(TreeNode* node) {
        return (!node->left && !node->right);
    }
    
    void findSum(TreeNode* node, int& sum, string& str) {
        if (node == NULL) return;
        
        str += to_string(node->val);
        
        if(isLeaf(node)) sum += stoi(str);
        
        findSum(node->left, sum, str);
        findSum(node->right, sum, str);
        str.pop_back();
    }    
    
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        string str = "";
        findSum(root, sum, str);
        return sum;
    }
};