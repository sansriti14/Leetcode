class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.length();
        vector<vector<int>> large_groups;
        
        int start = 0;
        while(start <= n - 3) {
            int end = start;
            while(end < n && s[start] == s[end]) end++;
            if(end - start >= 3) {
                large_groups.push_back({start, end - 1});
            }
            
            start = end;
        }
        
        return large_groups;
    }
};