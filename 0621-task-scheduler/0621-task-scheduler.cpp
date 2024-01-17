class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int num_tasks = tasks.size();
        
        if(n == 0) return num_tasks;
        
        unordered_map<char, int> mp;
        int max_freq = 0;
        for(auto it: tasks) {
            mp[it]++;
            max_freq = max(max_freq, mp[it]);
        }
        
        int min_time = (max_freq - 1) * (n + 1);
        for(auto it: mp) {
            if(it.second == max_freq)
                min_time++;
        }
        
        return (min_time < num_tasks) ? num_tasks : min_time;
    }
};