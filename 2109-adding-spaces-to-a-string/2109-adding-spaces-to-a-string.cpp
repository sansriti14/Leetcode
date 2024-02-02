class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int j = 0;
        for(int i = 0; i < spaces.size(); i++) {
            while(j < spaces[i]) {
                ans += s[j];
                j++;
            }
            
            ans += " ";
        }
        
        while(j < s.length()) ans += s[j++];
        return ans;
    }
};