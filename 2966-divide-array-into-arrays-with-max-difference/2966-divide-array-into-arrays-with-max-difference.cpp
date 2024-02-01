class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        
        for(int i = 0; i <= nums.size() - 3; i += 3) {
            vector<int> temp;
            temp.push_back(nums[i]);
            if(nums[i + 1] - nums[i] <= k) 
                temp.push_back(nums[i + 1]);
            else return vector<vector<int>> {};
            if(nums[i + 2] - nums[i + 1] <= k && nums[i + 2] - nums[i] <= k)
                temp.push_back(nums[i + 2]);
            else return vector<vector<int>> {};
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};