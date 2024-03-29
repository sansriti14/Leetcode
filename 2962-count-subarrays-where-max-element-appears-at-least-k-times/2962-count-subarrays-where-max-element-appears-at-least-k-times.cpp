class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return 0;
        
        int maxElement = *max_element(begin(nums), end(nums));
        int max_element_count = 0;
        
        long long numSubarrays = 0;
        
        int i = 0, j = 0;
        while (j < n) {
            max_element_count += (nums[j] == maxElement);
            
            while (max_element_count >= k) {
                max_element_count -= (nums[i++] == maxElement);
            }
            
            numSubarrays += i;
            j++;
        }
        
        return numSubarrays;
    }
};