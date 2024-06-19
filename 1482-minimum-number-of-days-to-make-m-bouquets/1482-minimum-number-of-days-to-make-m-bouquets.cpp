class Solution {
private:
    bool check(vector<int>& bloomDay, int m, int k,int mid) {
        int count = 0;
        int total = 0;
        
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                count++;
                if (count == k) {
                    total++;
                    count = 0;
                }
            }
            
            else count = 0;
        }
        
        return (total >= m);
    }
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 0;
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        
        while(start <= end) {
            int mid = (start + end) / 2;
            if (check(bloomDay, m, k, mid)) {
                ans = mid;
                end = mid - 1;
            }
            
            else start = mid + 1;
        }
            
        return ans;
    }
};