class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        int i = 0;
        while(i < n) {
            while(i < n && sentence[i] != ' ') i++;
            if(i > 0 && i < n - 1 && tolower(sentence[i - 1]) != tolower(sentence[i + 1])) 
                return false;
            else i++;
        }
        
        return (sentence[0] == sentence[n - 1]);
    }
};