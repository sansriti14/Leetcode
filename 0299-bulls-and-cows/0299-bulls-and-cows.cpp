class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        unordered_map<char, int> mp;
        
        int num_bulls = 0, num_cows = 0;
        for(int i = 0; i < n; i++) {
            mp[secret[i]]++;
            if(secret[i] == guess[i]) {
                --mp[secret[i]];
                ++num_bulls;
            }
        }

         for(int i = 0; i < n; i++) {   
            if(secret[i] == guess[i]) continue;
            if(mp.find(guess[i]) != mp.end() && mp[guess[i]] > 0) {
                ++num_cows;
                --mp[guess[i]];
            }
        }
        
        string hint = to_string(num_bulls) + 'A' + to_string(num_cows) + 'B';
        
        return hint;
    }
};