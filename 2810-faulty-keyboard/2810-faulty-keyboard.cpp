class Solution {
public:
    string finalString(string s) {
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == 'i') {
                int count = 0;
                int j = i;
                while(j < n && s[j] == 'i') {
                    j++;
                    count++;
                }
                
                if(count % 2) reverse(s.begin(), s.begin() + i);
                i = j;
            }
        }
        
        string final_string = "";
        for(int i = 0; i < n; i++) {
            if(s[i] != 'i')
                final_string += s[i];
        }
        
        return final_string;
    }
};