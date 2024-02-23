class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.length();
        vector<int>ans(26);
        int mx = 1;
        for(int i=0;i<n;i++) {
            if(i>0 && (s[i]-s[i-1]==1 || s[i-1]-s[i]==25)) mx++;
            else mx=1;
            int j = s[i]-'a';
            ans[j] = max(mx, ans[j]);
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};