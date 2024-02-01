class Solution {
public:
    int longestBeautifulSubstring(string word) { 
        int n = word.size();
        if(n < 5) return 0;
        
        int max_length = 0;
        for(int i = 0; i < n - 1; i++) {
            if(word[i] != 'a') continue;
            int currLength = 1, uniqueCount = 1;
            while(i < n - 1 && word[i] <= word[i + 1]) {
                currLength++;
                uniqueCount += (word[i] < word[i + 1]) ? 1 : 0;
                i++;
            }
            
            if(uniqueCount == 5) 
                max_length = max(max_length, currLength);
        }

        return max_length;
    }
};