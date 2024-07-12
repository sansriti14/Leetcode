class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char a = 'a', b = 'b';
        int num_a = 0, num_b = 0;
        
        if (y > x) {
            swap(a, b);
            swap(x, y);
        }
        
        int maxGain = 0;
        for (char &ch: s) {
            if (ch == a) num_a++;
            
            else if (ch == b) {
                if (num_a > 0) {
                    maxGain += x;
                    num_a--;
                }
                
                else num_b++;
            }
            
            else {
                maxGain += y * min(num_a, num_b);
                num_a = num_b = 0;
            }
        }
        
        return (maxGain + y * min(num_a, num_b));
    }
};