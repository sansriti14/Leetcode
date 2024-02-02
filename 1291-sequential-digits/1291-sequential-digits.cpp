class Solution {
private:
    void buildNumber(int digit, int num, int low, int high, vector<int>& ans) {
        if(num >= low && num <= high) ans.push_back(num);
        
        if(num > high || digit > 9) return;
        buildNumber(digit + 1, num * 10 + digit, low, high, ans);
    }
    
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i = 1; i < 10; i++) {
            buildNumber(i, 0, low, high, ans);
        }
        
        sort(begin(ans), end(ans));
        return ans;
    }
};