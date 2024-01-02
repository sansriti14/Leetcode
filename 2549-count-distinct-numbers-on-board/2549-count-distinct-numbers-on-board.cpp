class Solution {
public:
    int distinctIntegers(int n) {
        queue<int> q;
        q.push(n);
        int count = 1;
        vector<bool> visited(n + 1);
        
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            
            for(int i = 1; i < top; i++) {
                if(top % i == 1 && !visited[i]) {
                    visited[i]=true;
                    count++;
                    q.push(i);
                }
            }
        }
        
        return count;
    }
};