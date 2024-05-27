class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i <= n; i++) {
            int x = n;
            int low = 0, high = n - 1;
            
             while (low <= high) {
                 int mid = low + (high - low) / 2;
                 
                 if (nums[mid] >= i) {
                     x = mid;
                     high = mid - 1;
                 }
                 
                 else low = mid + 1;
             }
            
             if((n - x) == i) return i;
        }
        
        return -1;
    }
};