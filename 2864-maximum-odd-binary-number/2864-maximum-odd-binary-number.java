class Solution {
    public String maximumOddBinaryNumber(String s) {
        int n = s.length();
        int num_ones = 0;
        for(int i = 0; i < n; i++) {
            if(s.charAt(i) == '1') num_ones++;
        }
        
        int num_zeros = n - num_ones;
        
        StringBuilder maxOddNumber = new StringBuilder();
        while(--num_ones > 0) maxOddNumber.append('1');
        while(num_zeros-- > 0) maxOddNumber.append('0');
        
        maxOddNumber.append('1');
        
        return maxOddNumber.toString();
    }
}