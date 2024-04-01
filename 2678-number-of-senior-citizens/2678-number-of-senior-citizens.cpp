class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        
        for(auto detail: details) {
            string age = "";
            age += detail[11];
            age += detail[12];
            
            if(stoi(age) > 60) count++;
        }
        
        return count;
    }
};