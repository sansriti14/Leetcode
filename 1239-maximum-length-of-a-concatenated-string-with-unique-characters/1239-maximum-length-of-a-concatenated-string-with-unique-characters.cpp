class Solution {    
private:
    bool hasUniqueChars(string str) {
        unordered_set<char> st;
        for(auto ch: str) {
            if(st.find(ch) != st.end()) return false;
            st.insert(ch);
        }
        
        return true;
    }
    
    int findMaxLength(int index, string curr_str, vector<string>& arr) {
        if(index >= arr.size()) return 0;
        
        int not_pick = findMaxLength(index + 1, curr_str, arr);
        int pick = -1e9;
        if(hasUniqueChars(curr_str + arr[index])) {
            pick = max(not_pick, (int) arr[index].length() + findMaxLength(index + 1, curr_str + arr[index], arr));
        }
        
        return max(pick, not_pick);
    }
    
public:
    int maxLength(vector<string>& arr) {
        return findMaxLength(0, "", arr);
    }
};