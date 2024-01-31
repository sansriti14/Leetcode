class Solution {    
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
       priority_queue<int> pq;
        long long max_point = 0;
        for(int i = 0; i < reward1.size(); i++) {
           pq.push(reward1[i] - reward2[i]);
            max_point += reward2[i];
        }
        
        while(k != 0) {
            max_point += pq.top();
            pq.pop();
            k--;
        }
        return max_point;
    }
};