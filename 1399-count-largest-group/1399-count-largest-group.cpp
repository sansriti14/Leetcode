class Solution {
private:
    int sumOfDigits(int num) {
        int sum = 0;
        while(num) {
            sum += (num % 10);
            num = num / 10;
        }
        
        return sum;
    }
    
public:
    int countLargestGroup(int n) {
        vector<int> freq (37, 0);
        for(int i = 1; i <= n; i ++) {
            freq[sumOfDigits(i)]++;
        }
        
        int max_size = 0;
        for(auto it: freq) {
            max_size = max(max_size, it);
        }
        
        int count = 0;
        for(auto it: freq) {
            if(it == max_size) count++;
        }
            
        return count;
    }
};