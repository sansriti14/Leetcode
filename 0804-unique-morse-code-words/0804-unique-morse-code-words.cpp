class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse_code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> encoded;
        
        for(int i = 0; i < words.size(); i++) {
            string curr_string = words[i];
            string code = "";
            for(auto ch: curr_string) {
                code += morse_code[ch - 'a'];
            }
            encoded.insert(code);
        }
        
        return encoded.size();
    }
};