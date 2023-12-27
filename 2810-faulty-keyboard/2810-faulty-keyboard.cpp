class Solution {
public:
    string finalString(string s) {
        string final_string = "";
        
        for(auto ch: s) {
            if(ch != 'i')
                final_string += ch;
            else reverse(final_string.begin(), final_string.end());
        }
        
        return final_string;
    }
};