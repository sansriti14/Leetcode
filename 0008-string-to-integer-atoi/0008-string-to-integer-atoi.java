class Solution {
    public int myAtoi(String s) {
        int n = s.length();
        int i = 0;
        while(i < n && s.charAt(i) == ' ') i++;
        if(i == n) return 0;
        
        int sign = 1;
        if(s.charAt(i) == '-') sign = -1;
        
        long num = 0;
        if(s.charAt(i) == '-' || s.charAt(i) == '+') ++i;
        while(i < n && s.charAt(i) == '0') i++;
        
        int j = i;
        while(j < n && Character.isDigit(s.charAt(j))) j++;
        
        if(j - i > 10) return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        
        long place = (long)Math.pow(10, j - i - 1);
        
        while(i < j) {
            num += ((s.charAt(i) - '0') * place);
            place /= 10;
            i++;
        }
        
        num = num * sign;
        if(num < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        if(num > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        return (int)num;
    }
}