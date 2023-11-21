class Solution {
private:
    int reverseNum(int n) {
        int revNum = 0;
        while(n > 0) {
            revNum = revNum * 10 + (n % 10);
            n /= 10;
        }
        
        return revNum;
    }
    
public:
    int countNicePairs(vector<int>& nums) {
        long long count = 0;
        unordered_map<int, long> mp;
        int mod = 1e9 + 7;
        
        for(auto& num : nums) {
            count = (count + mp[num - reverseNum(num)]++) % mod;
        }
        
        return count;
    }
};