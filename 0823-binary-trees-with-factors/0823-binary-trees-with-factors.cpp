class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        long long ans = 0, mod = 1e9 + 7;
        
        sort(A.begin(), A.end());
        unordered_map<int, long> mp;
        
        for (int i = 0; i < A.size(); i++) {
            mp[A[i]] = 1;
            for (int j = 0; j < i; j++)
                if (A[i] % A[j] == 0)
                    mp[A[i]] = (mp[A[i]] + mp[A[j]] * mp[A[i] / A[j]]) % mod;
            ans = (ans + mp[A[i]]) % mod;
        }
        return ans;
    }
};