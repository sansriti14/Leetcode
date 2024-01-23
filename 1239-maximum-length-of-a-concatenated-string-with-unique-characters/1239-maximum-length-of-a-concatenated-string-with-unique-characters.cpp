class Solution {
private:
    int findMaxLength(vector<string>& arr, int index, string str) {
        unordered_set<char> st (begin(str), end(str));
        
        if(st.size() != (int) str.length()) return 0;
        
        int curr_length = str.length();
        for(int i = index; i < arr.size(); i++) {
            curr_length = max(curr_length, findMaxLength(arr, i, str + arr[i]));
        }
        
        return curr_length;
    }
    
public:
    int maxLength(vector<string>& arr) {
        return findMaxLength(arr, 0, "");
    }
};