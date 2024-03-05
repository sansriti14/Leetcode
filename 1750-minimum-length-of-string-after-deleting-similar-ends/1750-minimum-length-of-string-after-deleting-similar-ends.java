class Solution {
    public int minimumLength(String s) {
        int n = s.length();
        
        int low = 0, high = n - 1;
        while (low < high) {
            if(s.charAt(low) != s.charAt(high)) break;
            
            char ch = s.charAt(low);
            while (low <= high && s.charAt(low) == ch) low++;
            while (low <= high && s.charAt(high) == ch) high--;
        }
        
        return high - low + 1;
    }
}