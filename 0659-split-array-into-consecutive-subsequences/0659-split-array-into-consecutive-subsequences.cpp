class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> last;
        
        for(auto it: nums) freq[it]++;
        
        for(auto it: nums) {
            if(freq[it] == 0) continue;
            
            freq[it]--;
            
            if(last[it - 1] > 0) {
                last[it - 1]--;
                last[it]++;
            }
            
            else if(freq[it + 1] > 0 && freq[it + 2] > 0) {
                freq[it + 1]--;
                freq[it + 2]--;
                last[it + 2]++;
            }
            
            else  return false;
        }
        
        return true;
    }
};