class Solution {
private:
    bool isPossible(int max_value, vector<int>& nums) {
        long long extra = 0;
        for(auto it: nums) {
            if(it <= max_value) extra += (max_value - it);
            else {
                if(it - max_value > extra) return false;
                else extra -= (it - max_value);
            }
        }
        
        return true;
    }
    
public:
    int minimizeArrayValue(vector<int>& nums) {
        int low = 0, high = *max_element(nums.begin(), nums.end());
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid, nums)) high = mid;
            else low = mid + 1;
        }
        
        return low;
    }
};