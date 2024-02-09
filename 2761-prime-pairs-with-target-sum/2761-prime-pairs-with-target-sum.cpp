class Solution {
private:
    void checkPrime(int n, vector<bool>& isPrime) {
        for(int i = 2; i * i <= n; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> isPrime(n + 1, true);
        checkPrime(n, isPrime);
        isPrime[1] = false;
        
        unordered_set<int> primes;
        primes.insert(2);
        
        for(int i = 1; i <= n; i += 2) {
            if(isPrime[i]) primes.insert(i);
        }
        
        vector<vector<int>> primePairs;
        vector<bool> taken (n + 1, false);
        
        for(auto x: primes) {
            int y = n - x;
            if(primes.find(y) != primes.end() && !taken[y]) {
                if(x > y) swap(x, y);
                primePairs.push_back({x, y});
                taken[x] = true;
                taken[y] = true;
            }
        }
        
        sort(begin(primePairs), end(primePairs));
        return primePairs;
    }
};