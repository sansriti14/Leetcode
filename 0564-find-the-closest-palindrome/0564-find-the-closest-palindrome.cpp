class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        // Edge case: "1"
        if (n == "1") return "0";

        // Store the original number as an integer
        long long original = stoll(n);
        
        // Candidates to consider
        set<long long> candidates;
        
        // 1. Add edge cases
        candidates.insert((long long)pow(10, len - 1) - 1); // 999...999
        candidates.insert((long long)pow(10, len) + 1);     // 100...001

        // 2. Use the first half of the number to generate palindromes
        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        vector<long long> possible_prefixes = {prefix - 1, prefix, prefix + 1};
        
        for (long long p : possible_prefixes) {
            string prefix_str = to_string(p);
            string palindrome;
            if (len % 2 == 0) {
                palindrome = prefix_str + string(prefix_str.rbegin(), prefix_str.rend());
            } else {
                palindrome = prefix_str + string(prefix_str.rbegin() + 1, prefix_str.rend());
            }
            candidates.insert(stoll(palindrome));
        }

        // Find the closest palindrome
        long long closest = -1;
        for (long long candidate : candidates) {
            if (candidate != original) {
                if (closest == -1 ||
                    abs(candidate - original) < abs(closest - original) ||
                    (abs(candidate - original) == abs(closest - original) && candidate < closest)) {
                    closest = candidate;
                }
            }
        }
        
        return to_string(closest);
    }
};
