class Solution {
    private void buildNumber(int digit, int num, int low, int high, List<Integer> ans) {
        if(num >= low && num <= high) ans.add(num);
        
        if(num > high || digit > 9) return;
        buildNumber(digit + 1, num * 10 + digit, low, high, ans);
    }
    
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> ans = new ArrayList<Integer>();
        for(int i = 1; i <= 9; i++) {
            buildNumber(i, 0, low, high, ans);
        }
        
        Collections.sort(ans);
        return ans;
    }
}