class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int low = 0, high = 0;
        int i = 0, j = 0;
        
        while(low < word1.size() && high < word2.size()) {
            if(word1[low][i++] != word2[high][j++]) return false;
            
            if(i == word1[low].size()) {
                i = 0;
                low++;
            }
            
            if(j == word2[high].size()) {
                j = 0;
                high++;
            }
        }
        
        return (low == word1.size() && high == word2.size());
    }
};