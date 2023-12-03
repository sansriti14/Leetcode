class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n);
        pre[0] = 0;
        suf[n-1] = 0;
        
        for(int i=1; i<n; i++) {
            pre[i] = pre[i-1] + nums[i-1];
            suf[i-1] = accumulate(nums.begin()+i, nums.end(), 0);
        }
        
        for(int i=0; i<n; i++) {
            if(pre[i] == suf[i])
                return i;
        }
        
        return -1;
    }
};