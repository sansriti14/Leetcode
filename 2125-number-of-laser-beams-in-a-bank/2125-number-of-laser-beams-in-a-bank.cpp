class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int num_beams = 0;
        
        int prev_lasers = 0, curr_lasers = 0;
        for(int i = 0; i < bank.size(); i++) {
            curr_lasers = 0;
            for(int j = 0; j < bank[0].size(); j++) {
                if(bank[i][j] == '1') {
                    curr_lasers++;
                }
            }
            
            if(curr_lasers) {
                num_beams += (prev_lasers * curr_lasers);
                prev_lasers = curr_lasers;
            }
        }
        
        return num_beams;
    }
};