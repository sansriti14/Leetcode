class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        if(n == 1) return new int[] {0};
        
        Stack<Integer> st = new Stack<Integer>();
        st.push(n - 1);
        int[] ans = new int[n];
        
        for(int i = n - 2; i >= 0; i--) {
            while(!st.empty() && temperatures[st.peek()] <= temperatures[i]) {
                st.pop();
            }
            
            ans[i] = (st.size() == 0) ? 0 : st.peek() - i;
            st.push(i);
        }
        
        return ans;
    }
}