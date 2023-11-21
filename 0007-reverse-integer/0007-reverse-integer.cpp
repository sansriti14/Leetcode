class Solution {
public:
    int reverse(int x) {
        long r = 0;
        while (x) {
            r = r*10 + x%10;
            x /= 10;
        }
        return (int(r) == r) * r;
    }
};