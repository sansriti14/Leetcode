class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        
        while (q.size() > 1) {
            int K = k;
               while (K > 1) {
                    int num = q.front();
                    q.pop();
                    q.push(num);
                    K--;
                }
            q.pop();
        }
        
        return q.front();
    }
};