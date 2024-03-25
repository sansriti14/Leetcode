class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;
        
        int maxAmount = 0;
        while (low < high) {
            int currAmount = (high - low) * min(height[low], height[high]);
            maxAmount = max(maxAmount, currAmount);
            
            if (height[low] < height[high]) low++;
            else high--;
        }
        
        return maxAmount;
    }
};