class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int max_removed = accumulate(begin(piles), end(piles), 0);
        
        priority_queue<int> pq(begin(piles), end(piles));
        while(k-- && !pq.empty()) {
            int num_stones = pq.top();
            pq.pop();
            
            max_removed -= (num_stones / 2);
            pq.push(num_stones - num_stones / 2);
        }
        
        return max_removed;
    }
}; 