class Solution {
private:
    int highestDigit(int num) {
        int highest_digit = 0;
        while(num) {
            highest_digit = max(highest_digit, num % 10);
            num = num / 10;
        }
        
        return highest_digit;
    }
    
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        int max_sum = -1;
        for(auto num: nums) {
            int highest_digit = highestDigit(num);
            if(mp.find(highest_digit) != mp.end()) {
                max_sum = max(max_sum, num + mp[highest_digit]);
                mp[highest_digit] = max(mp[highest_digit], num);
            }
            
            else mp[highest_digit] = num;
        }
        
        return max_sum;
    }
};