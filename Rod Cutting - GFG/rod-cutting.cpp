//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  private:
    int findMaxPrice(int price[], int n, int cutLength, int rodLength, vector<vector<int>>& store_prices) {
        if(cutLength > n) return -1e9;
        if(rodLength == 0) return 0;
        
        if(store_prices[cutLength][rodLength] != -1) return store_prices[cutLength][rodLength];
        
        int notCutPrice = findMaxPrice(price, n, cutLength+1, rodLength, store_prices);
        
        int cutPrice = -1e9;
        if(cutLength <= rodLength) {
            cutPrice = max(notCutPrice, price[cutLength - 1] + findMaxPrice(price, n, cutLength, rodLength - cutLength, store_prices));
        }
        
        return store_prices[cutLength][rodLength] = max(cutPrice, notCutPrice);
    }
    
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> store_prices (n+1, vector<int> (n+1, -1));
        return findMaxPrice(price, n, 1, n, store_prices);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends