class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        
        if(nums[n-1] > nums[0]) {
            for(int i=1; i<n; i++) {
                if(nums[i] < nums[i-1]) return false;
            }
        }
        
        else if(nums[n-1] < nums[0]){
            for(int i=1; i<n; i++) {
                if(nums[i] > nums[i-1]) return false;
            }
        }
        
        else {
            for(int i=1; i<n; i++) {
                if(nums[i] != nums[i-1]) return false;
            }
        }
        return true;
    }
};