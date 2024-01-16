class Solution {
public:
    int countPoints(string rings) {
        vector<unordered_set<char>> nums(10);
        
        for(int i = 0; i < rings.size() - 1; i+= 2) {
            char color = rings[i];
            int rod = rings[i + 1] - '0';
            
            nums[rod].insert(color);
        }
        
        int num_rods = 0;
        for(int i = 0; i < 10; i++) {
            if(nums[i].size() == 3) {
                num_rods++;
            }
        }
        
        return num_rods;
    }
};