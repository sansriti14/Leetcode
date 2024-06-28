class Solution {
public:
    int largestInteger(int num) {
        string str = to_string(num);
        vector<int> even_ele, odd_ele;
        
        for (auto &ch: str) {
            if ((ch - '0') % 2) {
                odd_ele.push_back(ch);
            }
            
            else {
                even_ele.push_back(ch);
            }
        }
        
        sort(even_ele.rbegin(), even_ele.rend());
        sort(odd_ele.rbegin(), odd_ele.rend());
        
        int even_index = 0, odd_index = 0;
        
        for (int i = 0; i < str.length(); i++) {
            str[i] = ((str[i] - '0') % 2) ? odd_ele[odd_index++] : even_ele[even_index++];
        }
        
        return stoi(str);
    }
};