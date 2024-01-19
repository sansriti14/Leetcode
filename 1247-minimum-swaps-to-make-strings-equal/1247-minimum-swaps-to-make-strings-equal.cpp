class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.length();
        
        int xy = 0, yx = 0;
        for(int i = 0; i < n; i++) {
            if(s1[i] == 'x' && s2[i] == 'y') xy++;
            else if(s1[i] == 'y' && s2[i] == 'x') yx++;
        }
        
        int rem1 = xy % 2;
        int rem2 = yx % 2;

        if((rem1 + rem2) % 2) return -1;
        int min_swaps = xy/2 + yx/2 + rem1 * 2;

        return min_swaps;
    }
};