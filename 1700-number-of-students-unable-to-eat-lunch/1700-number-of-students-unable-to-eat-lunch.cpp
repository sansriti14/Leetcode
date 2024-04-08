class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> preferred (2, 0);
        
        queue<int> q;
        for (auto preference: students) {
            preferred[preference]++;
            q.push(preference);
        }
        
        int index = 0;
        while (index < sandwiches.size() && preferred[sandwiches[index]] != 0) {
            if (q.front() == sandwiches[index]) {
                q.pop();
                preferred[sandwiches[index]]--;
                index++;
            }
            
            else {
                q.push(q.front());
                q.pop();
            }
        }
        
        return q.size();
    }
};