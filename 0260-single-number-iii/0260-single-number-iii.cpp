class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int curr_xor = 0;
        
        for (auto it: nums) {
            curr_xor ^= it;
        }
        
        int mask = 1;
        while (true) {
            if(curr_xor & mask) break;
            mask = mask << 1;
        }

        int first = 0, second = 0;
        for (auto it: nums) {
            if (it & mask) first ^= it;
            else second ^= it;
        }

        return {first, second};
    }
};