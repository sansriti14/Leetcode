class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        
        int i = 0, j = 0;
        while (j < n) {
            while (i < n && nums[i] != 0) i++;
            j = i;
            while (j < n && nums[j] == 0) j++;
            
            int length = (j - i);
            count += (((long long)length * (length + 1)) / 2);
            i = j;
        }
        
        return count;
    }
};