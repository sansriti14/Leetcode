class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto it: nums) {
            mp[it]++;
        }
        
        int min_operations = 0;
        for(auto it: mp) {
            int freq = it.second;
            
            while(freq > 0) {
                if(freq == 1) return -1;

                if(freq == 2 || freq == 4) freq -= 2;

                else freq -= 3;
                
                min_operations++;
            }
        }

        return min_operations;
    }
};