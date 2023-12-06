class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> m;
        for(int i = 0; i < rectangles.size(); i++){
            double ratio = (double)rectangles[i][0] / rectangles[i][1];
            
            m[ratio] = (m.find(ratio) == m.end()) ? 1 : m[ratio] + 1;
        }
        
        long long ans = 0;
        for(auto it : m){
            if(it.second > 1)
                ans += (it.second % 2) ? (long long) it.second * (it.second - 1) / 2 : (long long) it.second / 2 * (it.second - 1);
        }
        
        return ans;
    }
};