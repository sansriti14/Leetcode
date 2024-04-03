class Solution {
private:
    bool isValid(int row, int col, int m, int n) {
        return (row >= 0 && col >= 0 && row < m && col < n);
    }
    
    bool dfs(int curr_row, int curr_col, int m, int n, string& curr_word, string& word, vector<vector<bool>>& visited, vector<vector<char>>& board) {
        curr_word += board[curr_row][curr_col];

        if (curr_word == word) return true;
        if (curr_word.length() > word.length()) return false;

        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};

        visited[curr_row][curr_col] = true;

        for (int i = 0; i < 4; i++) {
            int adj_row = curr_row + delta_row[i];
            int adj_col = curr_col + delta_col[i];

            if (isValid(adj_row, adj_col, m, n) && !visited[adj_row][adj_col] && board[adj_row][adj_col] == word[curr_word.length()]) {
                if (dfs(adj_row, adj_col, m, n, curr_word, word, visited, board)) {
                    return true;
                }
            }
        }

        visited[curr_row][curr_col] = false;
        curr_word.pop_back();

        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> visited (m, vector<bool> (n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                string curr_word = "";
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, m, n, curr_word, word, visited, board) == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};