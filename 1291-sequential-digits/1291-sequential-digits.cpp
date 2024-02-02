class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        int min_length = to_string(low).length();
        int max_length = to_string(high).length();
        
        vector<int> ans;
        for(int i = min_length; i <= max_length; i++) {
            for(int j = 0; j < 10 - i; j++) {
                int num = stoi(str.substr(j, i));
                if(num >= low && num <= high) ans.push_back(num);
            }    
        }
        
        return ans;
    }
};