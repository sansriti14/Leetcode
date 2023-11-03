class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int min_cost = 0;
        int start_row = startPos[0], start_col = startPos[1], end_row = homePos[0], end_col = homePos[1];
        
        while(start_row != end_row) {
            start_row = (end_row > start_row) ? start_row + 1 : start_row - 1;
            min_cost += rowCosts[start_row];
        }
        
        while(start_col != end_col) {
            start_col = (end_col > start_col) ? start_col + 1 : start_col - 1;
            min_cost += colCosts[start_col];
        }
        
        return min_cost;
    }
};