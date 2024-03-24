class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        vector<int> vowels = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};
        
        int currVowels = 0;
        for(int i = 0; i < k; i++) {
            currVowels += vowels[s[i] - 'a'];
        }
        
        int maxVowels = currVowels;
        int i = k;
        while (i < n) {
            currVowels -= vowels[s[i - k] - 'a'];
            currVowels += vowels[s[i++] - 'a'];
            
            maxVowels = max(maxVowels, currVowels);
        }
        
        return maxVowels;
    }
};
