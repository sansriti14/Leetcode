class Solution {
public:
    int dp[20001]; 
    int findMaxPoints(int index, vector<int> &arr) {
        int n = arr.size();
        if(index >= n ) return 0;
        if(dp[index] != -1) return dp[index];
        
        int curr_value = arr[index];
        int curr_sum = arr[index];
        int i = index + 1;
        
        while(i < n && (arr[i] == curr_value || arr[i] == curr_value + 1)) {
            curr_sum = curr_sum + ((arr[i] == curr_value) ? arr[i] : 0);
            i++;
        }

        return dp[index] = max(curr_sum + findMaxPoints(i, arr), findMaxPoints(index + 1, arr));
    }
    
    int deleteAndEarn(vector<int>& arr) {
        int n = arr.size(); 
        memset(dp, -1, sizeof(dp));
        sort(arr.begin(), arr.end());

        return findMaxPoints(0, arr);
    }
};