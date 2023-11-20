//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>> store_max_gold (n, vector<int> (m, 0));
        
        for(int row = 0; row < n; row++)
            store_max_gold[row][0] = M[row][0];
        
        int delta_row[] = {-1, 0, +1};
        for(int col = 1; col < m; col++) {
            for(int row = 0; row < n; row++) {
                for(int i=0; i<3; i++) {
                    int new_row = row + delta_row[i];
                    int new_col = col - 1;
                    
                    if(new_row>=0 && new_row<n && new_col>=0 && new_col<m) 
                        store_max_gold[row][col] = max(store_max_gold[row][col], M[row][col] + store_max_gold[new_row][new_col]);
                }
            }
        }
        
        int max_gold = 0;
        for(int row=0; row<n; row++)
            max_gold = max(max_gold, store_max_gold[row][m-1]);
        
        return max_gold;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends