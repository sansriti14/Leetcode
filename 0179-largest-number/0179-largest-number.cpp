class Solution {
private:
    static bool comparator(const int& a, int& b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    
public:
    string largestNumber(vector<int>& nums) {
        sort(begin(nums), end(nums), comparator);
        
        string ans = "";
        for(auto it: nums) ans += to_string(it);
        
        int sum = 0;
        for(auto it: ans) {
            sum += (it - '0');
        }
        
        if(sum == 0) return "0";
        
        return ans;
    }
};