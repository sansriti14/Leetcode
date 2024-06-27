class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        int m = pattern.size();
        
        vector<bool> ans (n, true);
        
        for (int index = 0; index < n; index++) {
            string word = queries[index];
            
            int j = 0;
            for (int i = 0; i < word.size(); i++) {
                if (isupper(word[i]) && pattern[j] != word[i]) {
                    ans[index] = false;
                }
                
                else if(word[i] == pattern[j]) j++;
            }
            
            if (j != pattern.size()) ans[index] = false;
        }
        
        return ans;
    }
};