class Solution {
    bool isStateValid(unordered_map<char, int>& frequency) {
         return (frequency['c'] >= frequency['r']) &&
                (frequency['r'] >= frequency['o']) &&
                (frequency['o'] >= frequency['a']) && 
                (frequency['a'] >= frequency['k']);
    }
    
public:
    int minNumberOfFrogs(string croakSequence) {
        unordered_map<char, int> frequency;
        
        int numFrogs = 0;
        int minFrogs = 0;
        
        for (auto &sound: croakSequence) {
            frequency[sound]++;
            if (!isStateValid(frequency)) return -1;
            
            if (sound == 'c') numFrogs++;
            else if (sound == 'k') numFrogs--;
            
            minFrogs = max(minFrogs, numFrogs);
        }
        
        return (numFrogs == 0) ? minFrogs : -1;
    }
};
