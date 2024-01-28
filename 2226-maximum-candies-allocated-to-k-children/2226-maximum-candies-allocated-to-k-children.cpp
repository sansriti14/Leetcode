class Solution {
private:
    long long countChildren(int max_candies, vector<int>& candies) {
        long long count = 0;
        for(int i = 0; i < candies.size(); i++) {
            count += (candies[i] / max_candies);
        }
        
        return count;
    }
    
public:
    int maximumCandies(vector<int>& candies, long long k) {
        sort(begin(candies), end(candies));
        int n = candies.size();
        
        int low = 0, high = candies[n - 1];
        
        while(low < high) {
            int mid = (low + high + 1) / 2;
            if(countChildren(mid, candies) >= k) low = mid;
            else high = mid - 1;
        }
        
        return low;
    }
};