class Solution {
private:
    int countAtMost(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int num_subarrays = 0;
        int curr_distinct = 0;
        
        int i = 0, j = 0;
        while(j < nums.size()) {
            if(++freq[nums[j]] == 1) curr_distinct++;
            
            while(curr_distinct > k) {
                if(--freq[nums[i]] == 0) curr_distinct--;
                i++;
            }
            
            j++;
            num_subarrays += (j - i + 1);
        }
        
        return num_subarrays;
    }    
    
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countAtMost(nums, k) -  countAtMost(nums, k - 1);
    }
};