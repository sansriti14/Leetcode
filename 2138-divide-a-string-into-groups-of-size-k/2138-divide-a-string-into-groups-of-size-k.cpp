class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> ans;
        
        for(int i = 0; i < n; i += k) {
            string str = "";
            for(int j = i; j < i + k && j < n; j++) {
                str += s[j];
            }
            
            ans.push_back(str);
        }
        
        int m = ans.back().length();
        while(m++ < k) ans.back() += fill;
        
        return ans;
    }
};