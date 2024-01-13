class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        
        if(n != m) return false;
        
        if(s == goal){
            set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size(); 
        }

        int i = 0;
        int j = n - 1;

        while(i < j && s[i] == goal[i]){
            i++;
        }

        while(j >= 0 && s[j] == goal[j]){
            j--;
        }

        if(i < j){
            swap(s[i], s[j]);
        }

        return s == goal;
    }
};