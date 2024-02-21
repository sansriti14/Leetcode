class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq (begin(nums), end(nums));
        
        while(k--) {
            int num = pq.top();
            pq.pop();
            
            pq.push(-num);
            
            if(num >= 0) {
                if(k % 2 == 0) break;
                else k = 1;
            }
        }
        
        int max_sum = 0;
        while(!pq.empty()) {
            max_sum += pq.top();
            pq.pop();
        }
        
        return max_sum;
    }
};