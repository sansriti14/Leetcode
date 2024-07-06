class Solution {
public:
    int passThePillow(int n, int time) {
        n = n - 1;
        return ((time / n) % 2) ? 1 + n - (time % n) : 1 + (time % n);
    }
};