class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        int total_ones = accumulate(begin(nums), end(nums), 0);
        int total_zeros = n - total_ones;
        
        unordered_map<int, int> mp;
        int curr_ones = 0, curr_zeros = 0;
        
        mp[n] = total_zeros;
        int max_score = mp[n];
        
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] == 1) curr_ones++;
            else curr_zeros++;
            
            int left_score = total_zeros - curr_zeros;
            int right_score = curr_ones;
            mp[i] = (left_score + right_score);
            
            max_score = max(max_score, left_score + right_score);
        }
        
        vector<int> ans;
        for(auto [index, score]: mp) {
            if(score == max_score) ans.push_back(index);
        }
        
        return ans;
    }
};