class Solution {
private: 
    int findMaxOperations(vector<int>& nums, int penalty) {
        int max_operations = 0;
        for(auto it: nums) {
            max_operations += (it - 1) / penalty;
        }
        
        return max_operations;
    }
    
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        //sort(begin(nums), end(nums));
        int n = nums.size();
        int low = 1, high = 1e9;
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            int possible_max_operations = findMaxOperations(nums, mid);
            
            if(possible_max_operations > maxOperations) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};