class Solution {
public:
    bool isPalindrome(string s, int index, int i) { 
        int l = index, r = i;
        while(l <= r) {
            if(s[l++] != s[r--])
                return false;
        }
        
        return true;
    }
    
public:
    void doPartition(int index, string s, vector<string> &palindrome, vector<vector<string>> &ans) {
        if(index == s.length()) {
            ans.push_back(palindrome);
            return;
        }
        
        for(int i=index; i<s.length(); i++) {
            if(isPalindrome(s, index, i)) {
                palindrome.push_back(s.substr(index, i-index+1));
                doPartition(i+1, s, palindrome, ans);
                palindrome.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> palindrome;
        
        doPartition(0, s, palindrome, ans);
        return ans;
    }
};