class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        
        long long inOneRound = accumulate(begin(chalk), end(chalk), (long long)0);
        int m = k / inOneRound;
        k -= (inOneRound * m);
        
        int i = 0;
        while (k >= chalk[i]) {
            k -= chalk[i];
            i++;
        }
        
        return i;
    }
};