class Solution {
public:
    int knightDialer(int n) {
        if(n == 1) return 10;
        
        vector<long long int> v(10,1);
        vector<long long int> temp(10);
        v[5]=0;
        
        int mod = 1e9 + 7;
        for(int i = 1; i < n; i++) {
            temp[0] = (v[4] + v[6]) % mod;
            temp[1] = (v[6] + v[8]) % mod;
            temp[2] = (v[7] + v[9]) % mod;
            temp[3] = (v[4] + v[8]) % mod;
            temp[4] = (v[0] + v[3] + v[9]) % mod;
            temp[6] = (v[0] + v[1] + v[7]) % mod;
            temp[7] = (v[2] + v[6]) % mod;
            temp[8] = (v[1] + v[3]) % mod;
            temp[9] = (v[2] + v[4]) % mod;
            
            for(int i = 0; i < 10; i++)
                v[i] = temp[i];
        }
        
        int sum=0;
        for(int i = 0; i < 10; i++)
            sum = (sum + v[i]) % mod;
        return sum;
    }
};