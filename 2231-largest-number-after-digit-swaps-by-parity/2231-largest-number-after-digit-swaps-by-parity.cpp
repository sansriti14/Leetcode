class Solution {
public:
    int largestInteger(int num) {
        string str = to_string(num);
        
        vector<int> even_indices, odd_indices;
        vector<int> even_ele, odd_ele;
        
        for (int i = 0; i < str.length(); i++) {
            if ((str[i] - '0') % 2) {
                odd_indices.push_back(i);
                odd_ele.push_back(str[i]);
            }
            
            else {
                even_indices.push_back(i);
                even_ele.push_back(str[i]);
            }
        }
        
        sort(odd_indices.begin(), odd_indices.end());
        sort(even_indices.begin(), even_indices.end());
        sort(even_ele.rbegin(), even_ele.rend());
        sort(odd_ele.rbegin(), odd_ele.rend());
        
        str.clear();
        for (int i = 0; i < odd_indices.size(); i++) {
            str[odd_indices[i]] = odd_ele[i];
        }
        
        for (int i = 0; i < even_indices.size(); i++) {
            str[even_indices[i]] = even_ele[i];
        }
        
        return stoi(str);
    }
};