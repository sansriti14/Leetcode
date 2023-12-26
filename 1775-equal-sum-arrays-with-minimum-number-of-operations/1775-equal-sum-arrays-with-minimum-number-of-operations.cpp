class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if(6 * nums1.size() < 1 * nums2.size() || 6 * nums2.size() < 1 * nums1.size())
            return -1;
        
        vector<int>arr(6);
        int diff = accumulate(begin(nums1), end(nums1), 0) - accumulate(begin(nums2), end(nums2), 0);
        if(diff > 0) swap(nums1, nums2);
        for(int &num : nums1) arr[6 - num]++;  
        for(int &num : nums2) arr[num - 1]++;        
        diff = abs(diff);
        
        int count = 0, j = 5;
        while(diff > 0) {
            if(arr[j]) {
                count += min(arr[j], (int)ceil(1.0 * diff / j));
                diff -= arr[j] * j;
                
                if(diff <= 0) return count;                
            }
            
			j--;
		}
        
        return count;
    }
};