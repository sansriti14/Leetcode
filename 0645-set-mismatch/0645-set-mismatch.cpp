class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
    
        long long sum1 = (n * (n + 1)) / 2;
        long long sum2 = (n * (n + 1) * (2 * n + 1)) / 6;
        long long s1 = 0, s2 = 0;
        
        for(auto it: nums) {
            s1 += it;
            s2 += (long long)it * (long long)it;
        }
        
        long long repeating = ((s1 - sum1) + ((s2 - sum2) / (s1 - sum1))) / 2;
        long long missing = repeating - (s1 - sum1);
        
        return {(int)repeating, (int)missing};
    }
};