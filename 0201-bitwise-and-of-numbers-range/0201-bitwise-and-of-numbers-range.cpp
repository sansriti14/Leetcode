class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int lsb_zeros = 0;
        
        while(left != right) {
            left >>= 1;
            right >>= 1;
            lsb_zeros++;
        }
        
        return left << lsb_zeros;
    }
};