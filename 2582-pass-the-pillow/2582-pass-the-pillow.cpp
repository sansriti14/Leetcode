class Solution {
public:
    int passThePillow(int n, int time) {
        if (time < n) return time + 1;
        
        return ((time / (n - 1)) % 2 == 0) ? 1 + time % (n - 1) : n - (time % (n - 1));
    }
};