class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        int count[10] = {};
        for (auto dig : digits)
            ++count[dig];
        
        for (int i = 1; i < 10; ++i) {
            for (int j = 0; count[i] > 0 && j < 10; ++j) {
                for (int k = 0; count[j] > (i == j) && k < 10; k += 2) {
                    if (count[k] > (k == i) + (k == j))
                        ans.push_back(i * 100 + j * 10 + k);
                }
            }
        }
        
        return ans;
    }
};