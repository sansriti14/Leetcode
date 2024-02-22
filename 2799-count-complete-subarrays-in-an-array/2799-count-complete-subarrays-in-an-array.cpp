class Solution {
private:
    int countAtMost(vector<int>& nums, unordered_map<int, int> freq, int k) {
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
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto it: nums) freq[it]++;
        
        int k = freq.size();
        freq.clear();
        return countAtMost(nums, freq, k) -  countAtMost(nums, freq, k - 1);
    }
};