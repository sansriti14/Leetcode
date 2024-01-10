/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
    void dfs(unordered_map<int, Employee*>& m, int id, int& sum) {
        sum += m[id]->importance;
        
        for(auto x: m[id]->subordinates) {
            dfs(m, x, sum);
        }
    }
    
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*>m;
        
        for(auto x: employees) {
            m[x->id] = x;
        }
        
        int sum = 0;
        dfs(m, id, sum);
        
        return sum;
    }
};