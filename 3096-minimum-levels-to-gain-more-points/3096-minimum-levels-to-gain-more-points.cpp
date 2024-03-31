class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        
        for (auto &it: possible) 
            if (it == 0) it = -1;
        
        int totalSum = accumulate(begin(possible), end(possible), 0);
        
        int ans = 0;
        int curr_score = 0;
        for(int i = 0; i < possible.size() - 1; i++) {
            curr_score += possible[i];
            if(totalSum - curr_score < curr_score) return i + 1;
        }
        
        return -1;
    }
};