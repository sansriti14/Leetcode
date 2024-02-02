class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder ans = new StringBuilder();
        int j = 0;
        for(int i = 0; i < spaces.length; i++) {
            while(j < s.length() && j < spaces[i]) {
                ans.append(s.charAt(j));
                j++;
            }
            
            ans.append(" ");
        }
        
        while(j < s.length()) ans.append(s.charAt(j++));
        return ans.toString();
    }
}