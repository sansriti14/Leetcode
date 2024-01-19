class Solution {
private:
    void createDictionary(string& s, vector<string>& dictionary, int& max_length) {
        int n = s.length();
        int i = 0;
        while(i < n) {
            string str = "";
            while(i < n && s[i] != ' ') {
                str += s[i];
                i++;
            }
            
            i++;
            dictionary.push_back(str);
            int curr_length = str.length();
            max_length = max(max_length, curr_length);
        }
    }
    
public:
    vector<string> printVertically(string s) {
        vector<string> dictionary;
        int max_length = 0;
        createDictionary(s, dictionary, max_length);
        
        vector<string> ans;
        for(int i = 0; i < max_length; i++) {
            string temp = "";
            for(int j = 0; j < dictionary.size(); j++) {
                if(i >= dictionary[j].length()) temp += ' ';
                else temp += dictionary[j][i];
            }
            
            while(temp.back() == ' ') temp.pop_back();
            ans.push_back(temp);
        }
        
        return ans;
    }
};