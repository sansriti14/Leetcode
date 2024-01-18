class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> distinct_suffix (n + 1, 0);
        unordered_set<int> st;
        for(int i = n - 1; i >= 0; i--) {
            st.insert(nums[i]);
            distinct_suffix[i] = st.size();
        }
        
        st.clear();
        
        vector<int> distinct_diff (n);
        for(int i = 0; i < n; i++) {
            st.insert(nums[i]);
            int distinct_prefix = st.size();
            
            distinct_diff[i] = distinct_prefix - distinct_suffix[i + 1];
        }

        return distinct_diff;
    }
};