class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        int n = str.length();
        
        int k_beauty = 0;
        for(int i = 0; i < n - k + 1; i++) {
            string sub_string = str.substr(i, k);
            int number = stoi(sub_string);
            if(number != 0 && num % number == 0) {
                k_beauty++;
            }
            
        }
        return k_beauty;
    }
};