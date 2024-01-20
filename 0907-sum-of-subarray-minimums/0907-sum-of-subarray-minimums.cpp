using ll = long long;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        ll min_sum = 0;
        int mod = 1e9 + 7;
        stack<int> st;
        for(int i = 0; i <= arr.size(); i++) {
            while(!st.empty() && (i == arr.size() || arr[st.top()] >= arr[i])) {
                int mid = st.top();
                st.pop();
                int first_smaller_left = st.empty() ? -1 : st.top();
                int first_smaller_right = i;

                ll count = (mid - first_smaller_left) * (first_smaller_right - mid) % mod;

                min_sum += (count * arr[mid]) % mod;
                min_sum %= mod;
            }
            
            st.push(i);
        }
        
        return min_sum;
    }
};