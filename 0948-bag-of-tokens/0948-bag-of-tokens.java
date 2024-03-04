class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);
             
        int max_score = 0;
        int curr_score = 0;
        
        int low = 0, high = tokens.length - 1;
        while(low <= high) {
            if(power >= tokens[low]) {
                power -= tokens[low++];
                max_score = Math.max(max_score, ++curr_score);
            }
            
            else if(max_score >= 1) {
                power += tokens[high--];
                curr_score--;
            }
            
            else break;
        }
        
        return max_score;
    }
}