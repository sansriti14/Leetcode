class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        unordered_map<char, int> freq;
        
        int num_bulls = 0;
        for(int i = 0; i < n; i++) {
            freq[secret[i]]++;
            if(secret[i] == guess[i]) {
                --freq[secret[i]];
                ++num_bulls;
            }
        }

        int num_cows = 0;
        for(int i = 0; i < n; i++) {   
            if(secret[i] == guess[i]) continue;
            if(freq.find(guess[i]) != freq.end() && freq[guess[i]] > 0) {
                --freq[guess[i]];
                ++num_cows;
            }
        }
        
        string hint = to_string(num_bulls) + 'A' + to_string(num_cows) + 'B';
        return hint;
    }
};