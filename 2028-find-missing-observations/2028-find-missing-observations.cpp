class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int m_sum = accumulate(begin(rolls), end(rolls), 0);
        int n_sum = mean * (n + m) - m_sum;
        
        vector<int> ans;
        if (6 * n < n_sum || n > n_sum)
            return {};
        
        for (; n > 0; --n) {
            ans.push_back(min(6, n_sum - n + 1));
            n_sum -= ans.back();
        }
        
        return ans;
    }
};