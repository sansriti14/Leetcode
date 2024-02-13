class Solution {
    private Boolean isPalindrome(String word) {
        int n = word.length();
        int i = 0;
        while(i < n / 2) {
            if(word.charAt(i) != word.charAt(n - i - 1)) return false;
            i++;
        }
        
        return true;
    }
    
    public String firstPalindrome(String[] words) {
        for(String curr_word: words) {
            if(isPalindrome(curr_word)) return curr_word;
        }
        
        return "";
    }
}