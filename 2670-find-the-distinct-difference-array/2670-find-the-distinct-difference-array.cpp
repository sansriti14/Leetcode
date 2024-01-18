class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> prefixCount(51, 0), suffixCount(51, 0);
        int distinctPrefix = 0, distinctSuffix = 0;

        for(auto it: nums) {
          if(++suffixCount[it] == 1) 
              ++distinctSuffix;
        }
        
        vector<int> distinct_diff;
        for(auto it: nums) {
          if(++prefixCount[it] == 1)
            ++distinctPrefix;
            
          if(--suffixCount[it] == 0)
            --distinctSuffix;
            
          distinct_diff.push_back(distinctPrefix - distinctSuffix);
        }

        return distinct_diff;
    }
};