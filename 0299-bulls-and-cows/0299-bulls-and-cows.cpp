class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mp;
        for(auto digit: secret) {
            mp[digit]++;
        }
        
        int n = secret.length();
        string hint = "";
        
        int num_bulls = 0, num_cows = 0;
        for(int i = 0; i < n; i++) {
            if(secret[i] == guess[i]) {
                ++num_bulls;
                --mp[guess[i]];
            }
        }
        
         for(int i = 0; i < n; i++) {   
            if(secret[i] == guess[i]) continue;
            if(mp.find(guess[i]) != mp.end() && mp[guess[i]] > 0) {
                ++num_cows;
                --mp[guess[i]];
            }
        }
        
        hint += to_string(num_bulls);
        hint += 'A';
        hint += to_string(num_cows);
        hint += 'B';
        
        return hint;
    }
};