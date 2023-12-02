class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {        
        int n = nums.size();
        vector<int> next_greater(n, -1);
        
        stack<int> st;
        st.push(nums.back());
        
        for(int i = 2*n-1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            
            if(i < n && !st.empty()) 
                next_greater[i] = st.top();
            
            st.push(nums[i % n]);
        }
        
        return next_greater;
    }
};