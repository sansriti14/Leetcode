class Solution {
    public String maximumBinaryString(String binary) {
        StringBuilder ans = new StringBuilder();
        int n = binary.length();
        int i = 0;
        while(i < n && binary.charAt(i) == '1') {
            ans.append('1');
            i++;
        }
        
        int ones = 0, zeros = 0;
        for(; i < n; i++) {
            if(binary.charAt(i) == '0') zeros++;
            else ones++;
        }
        
        for(int j = 0; j < zeros - 1; j++) ans.append('1');
        
        if(zeros > 0) ans.append('0');
        
        for(int j = 0; j < ones; j++) ans.append('1');
        
        return ans.toString();
    }
}