class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens), end(tokens));
        
        int max_score = 0;
        int curr_score = 0;
        
        int low = 0, high = tokens.size() - 1;
        while(low <= high) {
            if(power >= tokens[low]) {
                power -= tokens[low];
                max_score = max(max_score, ++curr_score);
                low++;
            }
            
            else if(max_score >= 1) {
                power += tokens[high];
                curr_score--;
                high--;
            }
            
            else break;
        }
        
        return max_score;
    }
};