class Solution {
public:
    bool halvesAreAlike(string s) {
        int first_half = 0, second_half = 0;
        int n = s.length();
        
        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        
        for(int i = 0; i < n; i++) {
            if(st.find(tolower(s[i])) != st.end()) {
                if(i < n/2) first_half++;
                else second_half++;
            }  
        }
        
        return first_half == second_half;
    }
};