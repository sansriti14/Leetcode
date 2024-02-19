class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        
        map<int, int> mp;
        for(auto it: nums) mp[it]++;
        
        int num_operations = 0;
        int prev = 0;
        for (auto i = mp.end(); i != mp.begin(); i--) {
            num_operations += i -> second + prev;   
            prev += i -> second;        
        }
        
        return num_operations;
    }
};