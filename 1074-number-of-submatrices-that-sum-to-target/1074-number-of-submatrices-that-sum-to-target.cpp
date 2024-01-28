class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int row = 0; row < n; row++) {
            for(int col = 1; col < m; col++) {
                matrix[row][col] += matrix[row][col - 1];
            }
        }
        
        int ans = 0;
        for(int col1 = 0; col1 < m; col1++) {
            for(int col2 = col1; col2 < m; col2++) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int curr_sum = 0;
                for(int row = 0; row < n; row++) {
                    curr_sum += matrix[row][col2] - (col1 > 0 ? matrix[row][col1 - 1] : 0);
                    ans += ( mp.find(curr_sum - target) != mp.end()) ? mp[curr_sum - target] : 0;
                    mp[curr_sum]++;
                }
            }
        }
        
        return ans;
    }
};