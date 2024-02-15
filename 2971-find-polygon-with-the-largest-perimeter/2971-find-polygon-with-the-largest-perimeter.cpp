class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        
        long long perimeter = -1;
        long long curr_sum = 0;
        for(int i = 0; i < n; i++) {
            if(curr_sum > nums[i]) perimeter = (curr_sum + nums[i]);
            curr_sum += nums[i];
        }
        
        return perimeter;
    }
};