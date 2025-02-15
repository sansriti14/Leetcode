class Solution {
private:
    bool canPartition(int n, string num, int currSum, int index = 0) {
        if (index == num.size()) {
            return (currSum == n);
        }
        
        int sum = 0;
        for (int i = index; i < num.size(); i++) {
            sum = sum * 10 + (num[i] - '0');
            if (canPartition(n, num, currSum + sum, i + 1)) {
                return true;
            }
        }
        
        return false;
    }

public:
    int punishmentNumber(int n) {
        int punishmentNum = 0;
        for (int i = 1; i <= n; i++) {
            if (canPartition(i, to_string(i * i), 0, 0)) {  
                punishmentNum += (i * i);
            }
        }

        return punishmentNum;
    }
};