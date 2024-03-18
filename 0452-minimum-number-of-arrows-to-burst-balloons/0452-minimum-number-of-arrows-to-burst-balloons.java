class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, Comparator.comparingInt(a->a[0]));
        
        int count = 1;
        int currMin = points[0][0];
        int currMax = points[0][1];
        
        for(int i = 1; i < points.length; i++) { 
            if(points[i][0] <= currMax) {
                currMin = points[i][0];
                currMax = Math.min(currMax, points[i][1]);
            }
            
            else {
                count++;
                currMin = points[i][0];
                currMax = points[i][1];
            }
        }
        
        return count;
    }
}