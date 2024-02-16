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

    void getSequence(TreeNode* node, vector<int>& leaf_seq) {
        if(node == NULL) return;
        
        if (isLeaf(node)) {
            leaf_seq.push_back(node->val);
            return;
        }
        
        getSequence(node->left, leaf_seq);
        getSequence(node->right, leaf_seq);
    }    
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf_seq1;
        vector<int> leaf_seq2;
        
        getSequence(root1, leaf_seq1);
        getSequence(root2, leaf_seq2);
        
        if (leaf_seq1.size() != leaf_seq2.size()) {
            return false;
        }
        
        for (int i = 0; i < leaf_seq1.size(); i++) {
            if (leaf_seq1[i] != leaf_seq2[i]) {
                return false;
            }
        }
        
        return true;
    }
}; 