class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = accumulate(begin(nums), end(nums), 0);
        
        int leftSum = 0, rightSum = total;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            rightSum -= nums[i];
            ans.push_back(abs(rightSum - leftSum));
            leftSum += nums[i];
        }
        
        return ans;
    }
};