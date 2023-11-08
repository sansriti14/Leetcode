class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int low = 1, high = k+1;
        vector<int> ans;
        while (low <= high) {
            ans.push_back(low++);
            
            if (low <= high) 
                ans.push_back(high--);
        }
        
        for (int i = k+2; i <= n; i++)
            ans.push_back(i);
        
        return ans;
    }
};