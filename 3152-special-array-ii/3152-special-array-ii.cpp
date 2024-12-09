class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> group(n, 0);
        int groupId = 0;

        for (int i = 0; i < n; i++) {
            if (i > 0 && (nums[i] % 2 == nums[i - 1] % 2)) {
                groupId++;
            }
            group[i] = groupId;
        }

        vector<bool> ans;
        for (auto& query : queries) {
            int from = query[0];
            int to = query[1];
            ans.push_back(group[from] == group[to]);
        }

        return ans;
    }
};
