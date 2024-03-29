class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0) return 0;
        
        if (num < 0) {
            string s = to_string(abs(num));
            sort(s.rbegin(), s.rend());
            return -stoll(s);
        }
        
        string s = to_string(num);
        sort(s.begin(), s.end());
        
        int i = 0;
        while (s[i] == '0') i++;
        
        char ch = s[i];
        s.erase(s.begin() + i);
        s = ch + s;
        
        return stoll(s);
    }
};