//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    int findMinSum(int curr_row, int curr_col, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(curr_row == n-1) return triangle[curr_row][curr_col];
        if(dp[curr_row][curr_col] != -1) return dp[curr_row][curr_col];
        
        int down = triangle[curr_row][curr_col] + findMinSum(curr_row + 1, curr_col, n, triangle, dp);
        int diagonal_down = triangle[curr_row][curr_col] + findMinSum(curr_row + 1, curr_col + 1, n, triangle, dp);
        
        return dp[curr_row][curr_col] = min(down, diagonal_down);
    }
    
  public:
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return findMinSum(0, 0, n, triangle, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends