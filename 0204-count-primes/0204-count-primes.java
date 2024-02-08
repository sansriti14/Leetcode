class Solution {
    public int countPrimes(int n) {
        if(n < 3) return 0;
        
        Boolean isPrime[] = new Boolean[n + 1];
        Arrays.fill(isPrime, true);
            
        for(int i = 2; i * i <= n; i++) {
            if(isPrime[i] == true) {
                for(int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        int count = 0;
        for(int i = 1; i < n; i += 2) {
            if(isPrime[i] == true) count++;
        }
        
        return count;
    }
}