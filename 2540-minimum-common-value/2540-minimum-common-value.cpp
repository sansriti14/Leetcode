class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(nums1[i] == nums2[j]) return nums1[i];
            
            while(i < n && nums1[i] < nums2[j]) i++;
            
            while(j < m && nums1[i] > nums2[j]) j++;
        }
        
        return -1;
    }
};