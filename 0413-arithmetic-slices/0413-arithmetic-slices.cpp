class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        int numOfSubarrays = 0;
        int count = 0;
        
        for(int i = 0; i < n - 2; i++) {
            if(nums[i + 1] - nums[i] == nums[i + 2] - nums[i + 1]) {
                count++;
            }
            
            else {
                numOfSubarrays += ((count * (count + 1)) / 2);
                count = 0;
            }   
        }
        
        if (count) numOfSubarrays += ((count * (count + 1)) / 2);
        
        return numOfSubarrays;
    }
};