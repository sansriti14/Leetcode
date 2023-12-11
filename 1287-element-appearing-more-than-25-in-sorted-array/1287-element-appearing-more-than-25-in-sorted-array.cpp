class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int qtr = arr.size() / 4;
        int count = 1;
        int ans = arr[0];
        for (int i = 1 ; i < arr.size() ; i++) {

            if ( ans == arr[i]) count++;
            else count = 1;
            
            if (count > qtr) return arr[i];
            
            ans = arr[i];
        }

        return ans;
    }
};