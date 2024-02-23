class Solution {
    public int findSubstringInWraproundString(String s) {
        int n = s.length();
        
        int count[] = new int[26];
        
        int max_len_substring = 1;
        for(int i = 0; i < n; i++) {
            if(i > 0 && (s.charAt(i) - s.charAt(i - 1) == 1 || s.charAt(i - 1) - s.charAt(i) == 25)) {
                max_len_substring++;
            }
            
            else max_len_substring = 1;
            
            int index = s.charAt(i) - 'a';
            count[index] = Math.max(max_len_substring, count[index]);
        }
        
        return Arrays.stream(count).reduce(0, Integer::sum);
    }
}