class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        
        sort(begin(potions), end(potions));
        vector<int> pairs;
        for(int i = 0; i < n; i++) {
            int low = 0, high = m - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                
                long long product = (long long) spells[i] * potions[mid];
                if(product < success) low = mid + 1;
                else high = mid - 1;
            }
            
            pairs.push_back(m - low);
        }
        
        return pairs;
    }
        
};