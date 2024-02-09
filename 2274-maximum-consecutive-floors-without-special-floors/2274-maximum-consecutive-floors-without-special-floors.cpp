class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(begin(special), end(special));
        
        int n = special.size();
        int max_consecutive = 0;
        max_consecutive = max(special[0] - bottom, top - special[n - 1]);
        
        for(int i = 1; i < n; i++) {
            max_consecutive = max(max_consecutive, special[i] - special[i - 1] - 1);
        }
        
        return max_consecutive;
    }
};