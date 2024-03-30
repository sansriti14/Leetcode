class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        
        int totalSum = 0;
        for(int i = 0; i < possible.size(); i++) {
            if(possible[i] == 0) possible[i] = -1;
            totalSum += possible[i];
        }
        
        int currScore = 0;
        for(int i = 0; i < possible.size() - 1; i++) {
            currScore += possible[i];
            if(totalSum - currScore < currScore) return i + 1;
        }
        
        return -1;
    }
};