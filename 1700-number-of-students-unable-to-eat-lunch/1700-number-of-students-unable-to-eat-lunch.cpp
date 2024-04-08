class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = sandwiches.size();
        
        int preferred_circular = 0, preferred_square = 0;
        
        for (auto preference: students) {
            if (preference == 0) preferred_circular++;
            else preferred_square++;
        }
        
        int ans = n;
        for (int i = 0; i < n; i++) {
            if ((sandwiches[i] == 0 && preferred_circular == 0) || (sandwiches[i] == 1 && preferred_square == 0)) return ans;
            
            if (sandwiches[i] == 0) preferred_circular--;
            else preferred_square--;
            
            ans--;
        }

        return ans;
    }
};