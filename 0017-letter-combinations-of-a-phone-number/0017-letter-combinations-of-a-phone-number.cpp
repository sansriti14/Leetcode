class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> ans;
        if(n == 0) return ans;
        
        unordered_map<int, string> mp = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};

        ans.push_back("");
        for(int i = 0; i < n; i++) {
            vector<string> temp;
            
            string value = mp[digits[i] - '0'];
            for(int i = 0; i < value.size(); i++) {
                for(int j = 0; j < ans.size(); j++) {
                    temp.push_back(ans[j] + value[i]);
                }
            }
            
            ans = temp;
        }

        return ans;
    }
};