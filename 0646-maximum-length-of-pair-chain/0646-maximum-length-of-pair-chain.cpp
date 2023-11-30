class Solution {
private:
    static bool comparator(vector<int>& a, vector<int>& b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), comparator);
        
        int count = 1, curr = pairs[0][1];
        
        for(int i=1; i<n; i++) {
            if(pairs[i][0] > curr) {
                count++;
                curr = pairs[i][1];
            }
        }
        return count;
    }
};