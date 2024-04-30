class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long long> count(1024, 0); 
        long long ans = 0;
        int prefix_xor = 0;
        count[prefix_xor] = 1;

        for (auto ch : word) {
            int index = ch - 'a';
            prefix_xor ^= 1 << index;
            ans += count[prefix_xor];
            
            for (int i = 0; i < 10; i++) {
                ans += count[prefix_xor ^ (1 << i)];
            }
            
            count[prefix_xor]++;
        }

        return ans;
    }
};