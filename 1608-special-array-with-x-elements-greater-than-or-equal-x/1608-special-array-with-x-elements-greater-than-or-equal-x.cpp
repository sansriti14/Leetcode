class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        for (int i = 1; i <= nums.size(); i++) { 
            auto it = lower_bound(begin(nums), end(nums), i); 
            if (distance(it, end(nums)) == i) return i;
        }
        
        return -1;
    }
};