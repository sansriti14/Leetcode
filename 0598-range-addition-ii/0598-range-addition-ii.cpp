class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_a = m, min_b = n;
        
        for(int i = 0; i < ops.size(); i++) {
            min_a = min(min_a, ops[i][0]);
            min_b = min(min_b, ops[i][1]);
        }
        
        return (min_a * min_b);
    }
};