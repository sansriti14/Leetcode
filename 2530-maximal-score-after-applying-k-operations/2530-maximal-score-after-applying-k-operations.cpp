class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long max_score = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        
        while(k-- && !pq.empty()) {
            int ele = pq.top();
            pq.pop();
            
            max_score += ele;
            if((ele + 2)/3) {
                pq.push((ele + 2)/3);
            }
        }
        
        return max_score;
    }
};