class Solution {
    public int numberOfUniqueGoodSubsequences(String binary) {
        int mod = (int)1e9 + 7;
        int ends_with_zero = 0, ends_with_one = 0;
        int zeroPresent = 0;

        for (int i = 0; i < binary.length(); i++) {
            if (binary.charAt(i) == '0') {
                zeroPresent = 1;
                ends_with_zero = (ends_with_zero + ends_with_one) % mod;
            } else {
                ends_with_one = (ends_with_one + ends_with_zero + 1) % mod;
            }
        }

        return (ends_with_zero + ends_with_one + zeroPresent) % mod;
    }
}