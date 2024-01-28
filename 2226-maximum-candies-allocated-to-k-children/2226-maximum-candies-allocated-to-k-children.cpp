class Solution {  
public:
    int maximumCandies(vector<int>& candies, long long k) {
        sort(begin(candies), end(candies));
        int n = candies.size();
        
        int low = 0, high = candies[n - 1];
        
        while(low < high) {
            int mid = (low + high + 1) / 2;
            
            long long num_children = 0;
            for(auto pile_size: candies) {
                num_children += (pile_size / mid);
            }
            
            if(num_children >= k) low = mid;
            else high = mid - 1;
        }
        
        return low;
    }
};