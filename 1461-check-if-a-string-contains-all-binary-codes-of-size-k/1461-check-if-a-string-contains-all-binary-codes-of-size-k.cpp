class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int n = s.length();
        int i = 0;
        while(i <= n - k) {
            string substring = "";
            for(int j = i; j < i + k; j++) {
                substring += s[j];
            }
            
            st.insert(substring);
            if(st.size() == pow(2, k)) return true;
            substring.erase(substring.begin() + 0);
            i++;
        }
        
        return (st.size() == pow(2, k));
    }
};