class Solution {    
private:
    bool hasUniqueChars(string& str) {
        unordered_set<char> st;
        for(auto ch: str) {
            if(st.find(ch) != st.end()) return false;
            st.insert(ch);
        }
        
        return true;
    }
    
    int findMaxLength(int index, string& curr_str, vector<string>& arr) {
        int n = arr.size();
        if(index >= n) return 0;
        
        int not_pick = findMaxLength(index + 1, curr_str, arr);
        int pick = -1e9;
        string new_string = curr_str + arr[index];
        int length = arr[index].length();
        
        if(hasUniqueChars(new_string)) {
            pick = max(not_pick, length + findMaxLength(index + 1, new_string, arr));
        }
        
        return max(pick, not_pick);
    }
    
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string str = "";
        return findMaxLength(0, str, arr);
    }
};