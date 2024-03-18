class Solution {
    static class IntervalComparator implements Comparator<int[]> {
        public int compare(int[] a, int[] b) {
            return a[1] - b[1];
        }
    }

    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, new IntervalComparator());

        int[] prevInterval = intervals[0];
        int minRemovals = 0;

        for (int i = 1; i < intervals.length; i++) {
            if (prevInterval[1] > intervals[i][0]) {
                minRemovals++;
                
            } 
            
            else prevInterval = intervals[i];
        }

        return minRemovals;
    }
}
