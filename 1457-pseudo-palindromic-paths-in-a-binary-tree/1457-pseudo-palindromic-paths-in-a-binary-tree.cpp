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
    
    bool isPseudoPalindromic(unordered_map<int, int>& mp) {
        int odd = 0;
        for(auto it: mp) {
            if(it.second % 2)
                odd++;
        }

       return (odd <= 1);
    }
    
    void countPseudoPalindromicPaths(TreeNode* node, int& pseudo_palindromic, unordered_map<int, int>& mp) {
        if(node == NULL) return;
        
        mp[node->val]++;
        
        if(isLeaf(node) && isPseudoPalindromic(mp)) {
            pseudo_palindromic++;
        }
                
        countPseudoPalindromicPaths(node->left, pseudo_palindromic, mp);
        countPseudoPalindromicPaths(node->right, pseudo_palindromic, mp);
        mp[node->val]--;
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if(isLeaf(root)) return 1;
        
        int pseudo_palindromic = 0;
        unordered_map<int, int> mp;
        countPseudoPalindromicPaths(root, pseudo_palindromic, mp);
        return pseudo_palindromic;
    }
};