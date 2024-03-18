class Solution {
    private int findMaxProfit(int index, List<List<Integer>> offers, int[] dp) {
        if (index == offers.size()) return 0;
        if (dp[index] != -1) return dp[index];

        int notSell = findMaxProfit(index + 1, offers, dp);
        int nextIndex = offers.size();

        int low = index + 1;
        int high = offers.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (offers.get(mid).get(0) > offers.get(index).get(1)) {
                high = mid - 1;
                nextIndex = mid;
            } 
            
            else low = mid + 1;
        }

        int sell = offers.get(index).get(2) + findMaxProfit(nextIndex, offers, dp);

        return dp[index] = Math.max(sell, notSell);
    }

    public int maximizeTheProfit(int n, List<List<Integer>> offers) {
        int m = offers.size();
        Collections.sort(offers, Comparator.comparingInt(o -> o.get(0)));

        int[] dp = new int[m];
        Arrays.fill(dp, -1);

        return findMaxProfit(0, offers, dp);
    }
}
