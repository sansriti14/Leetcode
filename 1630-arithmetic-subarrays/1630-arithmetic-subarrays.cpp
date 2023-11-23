class Solution {
private:
    bool isAP(vector<int>& temp) {
        int n = temp.size();
        if(n <= 2) return true;
        
        int diff = temp[1] - temp[0];
        for(int i = 1; i < n; i++) {
            if(temp[i] - temp[i-1] != diff)
                return false;
        }
        
        return true;
    }
    
    bool solve(vector<int>& nums, int left, int right) {
        vector<int> temp (nums.begin() + left, nums.begin() + right + 1);
        sort(temp.begin(), temp.end());
        if(isAP(temp) == false) return false;
        return true;
    }
    
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> answer;
        for(int i = 0; i < m; i++) {
            if(solve(nums, l[i], r[i]) == false) {
                answer.push_back(false);
            }
            
            else answer.push_back(true);
        }
        
        return answer;
    }
};