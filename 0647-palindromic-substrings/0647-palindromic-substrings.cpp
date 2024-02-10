class Solution {
private:
    bool isPalindrome(string str) {
        int n = str.length();
        int i = -1;
        while(i++ < n / 2) {
            if(str[i] != str[n - i - 1]) return false;
        }
        
        return true;
    }
    
public:
    int countSubstrings(string s) {
        int n = s.length();
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[s[i]].push_back(i);
        }
        
        int count = 0;
        int i = -1;
        while(i++ < n) {
            for(auto j: mp[s[i]]) {
                if(j < i) continue;
                if(isPalindrome(s.substr(i, j - i + 1))) {
                    count++;
                }              
            }
        }
        
        return count;
    }
};