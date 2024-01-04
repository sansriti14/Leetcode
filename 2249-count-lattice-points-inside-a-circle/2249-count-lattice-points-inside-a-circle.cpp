class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int n = circles.size();
        set<pair<int, int>> s;
        
        for(int i = 0; i < n; i++) {
            int a = circles[i][0], b = circles[i][1], radius = circles[i][2];
            
            for(int x = -radius; x <= radius; x++) {
                for(int y = -radius; y <= radius; y++) {
                    if((x * x) + (y * y) <= (radius * radius)) {
                        s.insert({x + a, y + b});
                    }
                }
            }
        }
        
        return s.size();
    }
};