class Solution {
private:
    int reverseNum(string num) {
        reverse(num.begin(), num.end());
        return stoi(num);
    }
    
public:
    int countNicePairs(vector<int>& nums) {
        long long count = 0;
        unordered_map<int, long> mp;
        int mod = 1e9 + 7;
        
        for(auto& num : nums) {
            count = (count + mp[num - reverseNum(to_string(num))]++) % mod;
        }
        
        return count;
    }
};