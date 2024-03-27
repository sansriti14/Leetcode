class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        
        int n = nums.size();
        int i = 0, j = 0;
        
        int curr_product = 1;
        int count = 0;
        while (j < n) {
            curr_product *= nums[j];
            
            while (i <= j && curr_product >= k) {
                curr_product /= nums[i++];
            }
            
            count += (j - i + 1);
            j++;
        }
        
        return count;
    }
};