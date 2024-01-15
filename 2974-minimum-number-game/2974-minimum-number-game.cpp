class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq (begin(nums), end(nums));
        
        vector<int> arr;
        while(pq.size() > 1) {
            int smallest = pq.top();
            pq.pop();
            
            int second_smallest = pq.top();
            pq.pop();
            
            arr.push_back(second_smallest);
            arr.push_back(smallest);
        }
        
        return arr;
    }
};