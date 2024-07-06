class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long inOneRound = accumulate(begin(chalk), end(chalk), (long long)0);
        
        k %= inOneRound;
        
        int i = 0;
        while (k >= chalk[i]) {
            k -= chalk[i++];
        }
        
        return i;
    }
};