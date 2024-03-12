using piv = pair<int, vector<int>>;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans(k);
        priority_queue<piv> pq;
        
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                vector<int> temp = {nums1[i], nums2[j]};
                
                if (pq.size() < k) {
                    pq.push({sum, temp});
                }
                
                else if (sum < pq.top().first) {
                    pq.pop();
                    pq.push({sum, temp});
                } 
                
                else break;  
            }
        }
        
        int index = 0;
        while(k--) {
            ans[index++] = pq.top().second;
            pq.pop();
        }
        
        return ans;
    }
};