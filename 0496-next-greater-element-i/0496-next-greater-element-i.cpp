class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        if(n == 1) return {-1};
        
        unordered_map<int, int> mp;
        mp[nums2[n-1]] = -1;
        
        stack<int> st;
        st.push(nums2.back());
        
        for(int i = n-2; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            
            mp[nums2[i]] = (st.size() == 0) ? -1 : st.top();
            st.push(nums2[i]);
        }
        
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }
        
        return ans;
    }
};