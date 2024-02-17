class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        int n = heights.length;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (int i = 0; i < n - 1; i++) {
            int curr_diff = heights[i + 1] - heights[i];
            if (curr_diff > 0) {
                pq.add(curr_diff);
            }
            
            if (pq.size() > ladders) {
                bricks -= pq.poll();
            }
            
            if (bricks < 0) {
                return i;
            }
        }
        
        return n - 1;
    }
}