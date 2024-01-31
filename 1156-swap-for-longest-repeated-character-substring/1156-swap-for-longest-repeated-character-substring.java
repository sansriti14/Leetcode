class Solution {
    private void findRanges(String text, List<int[]>[] ranges) {
        int n = text.length();
        
        for (int i = 0; i < 26; i++) {
            ranges[i] = new ArrayList<>();
        }
        
        int i = 0, j = 0;
        while(i < n && j < n) {
            while(j < n - 1 && text.charAt(j) == text.charAt(j + 1)) j++;
            ranges[text.charAt(i) - 'a'].add(new int[]{i, j});
            i = j + 1;
            j = i;
        }
    }
    
    public int maxRepOpt1(String text) {
        List<int[]>[] ranges = new ArrayList[26];
        
        findRanges(text, ranges);
        
        int max_length = 1;
        for(int i = 0; i < 26; i++) {
            int total_ranges = ranges[i].size();
            
            for(int j = 0; j < total_ranges; j++) {
                int curr_start = ranges[i].get(j)[0];
                int curr_end = ranges[i].get(j)[1];
                
                int curr_length = curr_end - curr_start + 1;
                if(total_ranges > 1) curr_length ++;        
                max_length = Math.max(max_length, curr_length);
                
                if(j == 0) continue;
                
                int prev_start = ranges[i].get(j - 1)[0];
                int prev_end = ranges[i].get(j - 1)[1];
                if(prev_end + 2 == curr_start) {
                    curr_length = (prev_end - prev_start + 1) + (curr_end - curr_start + 1); 

                    if(total_ranges > 2) curr_length ++;
                    max_length = Math.max(max_length, curr_length);
                }
            }
        }
        
        return max_length;
        
        
    }
}
