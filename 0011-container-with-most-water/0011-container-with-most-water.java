class Solution {
    public int maxArea(int[] height) {
        int low = 0;
        int high = height.length - 1;
        
        int maxAmount = 0;
        while (low < high) {
            int currAmount = (high - low) * Math.min(height[low], height[high]);
            maxAmount = Math.max(maxAmount, currAmount);
            
            if (height[low] < height[high]) low++;
            else high--;
        }
        
        return maxAmount;
    }
}