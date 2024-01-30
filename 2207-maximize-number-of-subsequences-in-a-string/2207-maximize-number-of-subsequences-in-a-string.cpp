class Solution {
private:
    long long count(string S1, string S2) {
    int m = S1.size();
    vector<long long> count(2, 0); 
    for (int i = 0; i < m; i++) {
        for (int j = 1; j >= 0; j--) {
            if (S1[i] == S2[j]) {
                count[j] += (j == 0 ? 1 : count[j - 1]);
            }
        }
    }
 
    return count[1];
}
    
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        return max(count(pattern[0] + text, pattern), count(text + pattern[1], pattern));
    }
};