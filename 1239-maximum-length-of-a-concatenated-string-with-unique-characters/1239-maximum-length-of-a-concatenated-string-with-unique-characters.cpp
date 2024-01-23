class Solution {
private:
    int findMaxLength(vector<string>& arr, int index, string& str) {
        unordered_set<char> st (begin(str), end(str));
        
        if(st.size() != (int) str.length()) return 0;
        
        int curr_length = str.length();
        for(int i = index; i < arr.size(); i++) {
            string new_string = str + arr[i];
            curr_length = max(curr_length, findMaxLength(arr, i, new_string));
        }
        
        return curr_length;
    }
    
public:
    int maxLength(vector<string>& arr) {
        string str = "";
        return findMaxLength(arr, 0, str);
    }
};