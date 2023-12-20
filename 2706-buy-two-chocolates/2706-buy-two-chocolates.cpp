class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int first = INT_MAX, second = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < first) {
                second = first;
                first = prices[i];
            }
        
            else if(prices[i] < second)
                second = prices[i];
        }    
        int ans = money - (first + second);
        return ans >= 0 ? ans : money;
    }
};