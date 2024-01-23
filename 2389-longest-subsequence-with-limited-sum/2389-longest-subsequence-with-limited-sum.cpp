class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int total_sum = accumulate(begin(nums), end(nums), 0);
        sort(begin(nums), end(nums));
        
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            int curr_sum = total_sum;
            int length = n;
            
            while(curr_sum > queries[i]) curr_sum -= nums[--length];
            ans.push_back(length);
        }
        
        return ans;
    }
};