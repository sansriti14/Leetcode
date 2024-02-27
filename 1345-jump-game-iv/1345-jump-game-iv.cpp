class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        
        vector<bool> visited(n, false);
        visited[0] = true;
        
        queue<int> q;
        q.push(0);
        
        int minJumps = 0;
        while (!q.empty()) {
            int size = q.size();
            
            while(size--) {
                int curr = q.front();
                q.pop();
                
                if (curr == n - 1) return minJumps;
                
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
                
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
                
                for (auto it : mp[arr[curr]]) {
                    if (!visited[it]) {
                        visited[it] = true;
                        q.push(it);
                    }
                }
                
                mp.erase(arr[curr]);
            }
            
            minJumps++;
        }
        
        return -1;

    }
};