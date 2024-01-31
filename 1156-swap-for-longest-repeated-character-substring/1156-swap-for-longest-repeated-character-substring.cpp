class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.length();
        vector<pair<int, int>> ranges[26];
        
        int i = 0, j = 0;
        while(i < n && j < n) {
            while(j < n - 1 && text[j] == text[j + 1]) j++;
            ranges[text[i] - 'a'].push_back({i, j});
            i = j + 1;
            j = i;
        }
        
        int max_length = 1;
        for(int i = 0; i < 26; i++) {
            int total_ranges = ranges[i].size();
            
            for(int j = 0; j < total_ranges; j++) {
                auto [curr_start, curr_end] = ranges[i][j];
                
                int curr_length = curr_end - curr_start + 1;
                if(total_ranges > 1) curr_length += 1;        
                max_length = max(max_length, curr_length);
                
                if(j == 0) continue;
                
                auto [prev_start, prev_end] = ranges[i][j - 1];
                if(prev_end + 2 == curr_start) {
                    curr_length = (prev_end - prev_start + 1) + (curr_end - curr_start + 1); 

                    if(total_ranges > 2) curr_length += 1;
                    max_length = max(max_length, curr_length);
                }
            }
        }
        
        return max_length;
    }
};