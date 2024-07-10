class Solution {
public:
    int minOperations(vector<string>& logs) {
        int numOperations = 0;
        
        for (auto operation: logs) {
            string str = "";
            int i = 0;
            while (operation[i] != '/') {
                str += operation[i++];
            }
            
            if (str == "..") numOperations = max(0, numOperations - 1);
            else if (str != ".") numOperations++;
        }
        
        return (numOperations <= 0) ? 0 : numOperations;
    }
};