class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        
        if(n > m) return false;
        
        vector<int> freq(26, 0);
        for(auto ch: s1) {
            freq[ch - 'a']++;
        }
        
        int i = 0, j = 0;
        int count = n;
        
        while(j < m) {
            if(freq[s2[j++] - 'a']-- > 0) {
                count--;
            }
            
            if(count == 0) return true;
            
            if((j - i == n) && (freq[s2[i++] - 'a']++ >= 0)) {
                count++;
            }
        }
        
        return false;
    }
};