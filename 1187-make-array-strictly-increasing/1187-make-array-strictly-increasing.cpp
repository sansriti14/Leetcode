class Solution {
private:
    int solve(int prevValue, int currIndex, vector<int>& arr1, vector<int>& arr2, map<pair<int, int>, int>& dp) {
        if (currIndex == arr1.size()) return 0;
        if (dp.find({prevValue, currIndex}) != dp.end()) return dp[{prevValue, currIndex}];
        
        int notReplace = 1e9, replace = 1e9;
        
        int index = upper_bound(begin(arr2), end(arr2), prevValue) - begin(arr2);
        if (index < arr2.size()) {
            replace = 1 + solve(arr2[index], currIndex + 1, arr1, arr2, dp);
        }
        
        if (arr1[currIndex] > prevValue) {
            notReplace = solve(arr1[currIndex], currIndex + 1, arr1, arr2, dp);
        }
        
        return dp[{prevValue, currIndex}] = min(replace, notReplace);
    }
    
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(begin(arr2), end(arr2));
        
        map<pair<int, int>, int> dp;
        int min_operations = solve(-1, 0, arr1, arr2, dp);
        return (min_operations >= 1e9) ? -1 : min_operations;
    }
};