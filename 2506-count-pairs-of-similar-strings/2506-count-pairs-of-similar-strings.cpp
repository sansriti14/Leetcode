class Solution {
public:
    int similarPairs(vector<string>& words) {
        set<char> st;
        unordered_map<string, int> mp;
        for(auto word: words) {
            for(auto ch: word) {
                st.insert(ch);
            }
            
            string str = "";
            for(auto ch: st) str += ch;
            st.clear();
            mp[str]++;
        }
        
        int similar_strings = 0;
        for(auto it: mp) {
            int freq = it.second;
            if(freq > 1) {
                similar_strings += ((long long) (freq * (freq - 1)) / 2);
            }
        }
        
        return similar_strings;
    }
};