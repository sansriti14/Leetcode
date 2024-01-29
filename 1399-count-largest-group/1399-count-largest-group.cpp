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
        unordered_map<int, int> mp;
        for(int i = 1; i <= n; i ++) {
            mp[i] = sumOfDigits(i);
        }
        
        unordered_map<int, int> freq;
        int max_size = 0;
        for(auto it: mp) {
            freq[it.second]++;
            max_size = max(max_size, freq[it.second]);
        }
        
        int count = 0;
        for(auto it: freq) {
            if(it.second == max_size) count++;
        }
            
        return count;
    }
};