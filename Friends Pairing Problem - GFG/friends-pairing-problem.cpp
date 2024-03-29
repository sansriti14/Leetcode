//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{

public:
    int countFriendsPairings(int n) 
    { 
        vector<long long> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        
        int mod = 1e9 + 7;
        for(int i=3; i<n+1; i++) {
            dp[i] = (dp[i-1] + (i - 1) * dp[i-2]) % mod;
        }
        
        return dp[n] % mod;
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends