class Solution {
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
        int val = (mean * (rolls.size() + n)) - accumulate(rolls.begin() , rolls.end() , 0); 
        
        if(6 * n < val or val < 0 or val < n) 
            return {};
        
        int rem = val % n;
        vector<int> ans(n , val/n); 
        
        for(int i = 0 ; i < ans.size() ; ++i)
        {
            if(rem != 0) {
                ans[i] += 1;
                --rem;
            }
            else break;

        }
        return ans;
    }
};