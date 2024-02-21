class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq (begin(nums), end(nums));
        
        while(k--) {
            int num = pq.top();
            pq.pop();
            
            pq.push(-num);
        }
        
        int max_sum = 0;
        while(!pq.empty()) {
            max_sum += pq.top();
            pq.pop();
        }
        
        return max_sum;
    }
};