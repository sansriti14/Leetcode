class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m = score.size();
        int n = score[0].size();
        
        priority_queue<pair<int, int>> pq;
        for(int row = 0; row < m; row++) {
            pq.push({score[row][k], row});
        }
        
        vector<vector<int>> ans(m, vector<int>(n));
        int row = 0;
        while(!pq.empty()) {
            int curr_row = pq.top().second;
            pq.pop();

            for(int col = 0; col < n; col++) {
                ans[row][col] = score[curr_row][col]; 
            }
            
            row++;

        }
        
        return ans;
    }
};