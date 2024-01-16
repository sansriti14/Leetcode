class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int num_rows = grid.size();
        int num_cols = grid[0].size();
		
        int perimeter = 0;
        for(int row = 0; row < num_rows; row++) {
            for(int col = 0; col < num_cols; col++) {
                if(grid[row][col]) {
                    perimeter += (row == 0 ? 1 : !grid[row - 1][col]);
                    perimeter += (col == 0 ? 1 : !grid[row][col - 1]);
                    perimeter += (row == num_rows - 1 ? 1 : !grid[row + 1][col]);
                    perimeter += (col == num_cols - 1 ? 1 : !grid[row][col + 1]);
                }
            }
        }
            
        return perimeter;
    }
};