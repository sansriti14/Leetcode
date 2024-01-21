class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> range (n + 1, 0);
        for(int i = 0; i <= n; i++) {
            int left_range = max(0, i - ranges[i]);
            int right_range = min(n, i + ranges[i]);
            
            range[left_range] = max(range[left_range], right_range - left_range);
        }
        
        int curr_end  = 0;
        int max_reach = 0;
        int min_sprinklers = 0;
        for(int i = 0; i < n; i++) {
            max_reach = max(max_reach, range[i] + i);
            
            if(i == curr_end) {
                min_sprinklers++;
                curr_end = max_reach;
            }
        }
        
        return (curr_end >= n) ? min_sprinklers : -1;
    }
};