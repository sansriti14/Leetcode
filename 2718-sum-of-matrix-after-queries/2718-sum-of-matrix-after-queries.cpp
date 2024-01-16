class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        int num_queries = queries.size();
        
        vector<bool> rows_visited(n), cols_visited(n);
        int row_count = n, col_count = n;
        
        long long sum = 0;
        for(int i = num_queries - 1; i >= 0; i--) {
            int type = queries[i][0];
            int index = queries[i][1];
            int value = queries[i][2];
            
            if(type == 0) {
                if(rows_visited[index] == false) {
                    rows_visited[index] = true;
                    --row_count;
                    sum += (value * col_count);
                }
            } 
            
            else if(type == 1) {
                if(cols_visited[index] == false) {
                    cols_visited[index] = true;
                    --col_count;
                    sum += (value * row_count);
                }
            }
        }
        
        return sum;
    }
};