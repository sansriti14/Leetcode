using psi = pair<string, int>;

class Solution {
public:
    static bool comparator (const psi& a, const psi& b) {
        if(a.first.length() != b.first.length()) 
            return a.first.length() < b.first.length();
        return a.second < b.second;
    }
    
    string arrangeWords(string text) {
        int n = text.size();
        vector<psi> temp;
        string str = "";
        for(int i = 0; i <= n; i++) {
            if(text[i] == ' ' || i == n) {
                temp.push_back({str, i - str.length()});
                str.clear();
            }
            
            else str += text[i];
        }
        
        sort (begin(temp), end(temp), comparator);
        
        string ans = "";
        for(auto it: temp) {
            string word = it.first;
            word[0] = tolower(word[0]);
            ans += (word + ' ');
        }
        
        ans[0] = toupper(ans[0]);
        ans.pop_back();
        
        return ans;
    }
};