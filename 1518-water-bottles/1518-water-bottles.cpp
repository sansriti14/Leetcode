class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int maxDrink = 0;
        int numEmpty = 0;
        
        while (numBottles + numEmpty >= numExchange) {
            maxDrink += numBottles;
            numEmpty += numBottles;
            
            numBottles = numEmpty / numExchange;
            numEmpty = numEmpty % numExchange;
        }
        
        return maxDrink + numBottles;
    }
};