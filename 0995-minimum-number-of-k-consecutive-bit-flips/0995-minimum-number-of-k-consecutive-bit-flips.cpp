class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        
        int flipped = 0;
        int minFlips = 0;
        vector<bool> isFlipped(n, false);

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flipped ^= isFlipped[i - k];
            }
            
            if (flipped == nums[i]) {
                if (i + k > n) return -1;
                
                isFlipped[i] = true;
                flipped ^= 1;
                minFlips++;
            }
        }

        return minFlips;
    }
};