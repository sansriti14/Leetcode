class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();
        int alreadySatisfied = 0;
        int speciallySatisfied = 0;
        
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                alreadySatisfied += customers[i];
            }
            
            customers[i] *= grumpy[i];
        }
        
        for (int i = 1; i < n; i++) {
            customers[i] += customers[i - 1];
        }
        
        for (int i = minutes - 1; i < n; i++) {
            speciallySatisfied = max(speciallySatisfied, customers[i] - (i - minutes >= 0 ? customers[i - minutes] : 0));
        }
        
        return alreadySatisfied + speciallySatisfied;
    }
};