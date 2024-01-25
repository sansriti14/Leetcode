class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> st;
        vector<int> prefix_common;
        
        for(int i = 0; i < n; i++) {
            st.insert(A[i]);
            st.insert(B[i]);
            prefix_common.push_back(2 * (i + 1) - st.size());
        }
        
        return prefix_common;
    }
};