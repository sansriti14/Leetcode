class Solution {
public:
    int numSteps(string s) {
        int steps = 0;

        while (s != "1") {
            if (s.back() == '1') {
                while (!s.empty() && s.back() == '1') {
                    s.pop_back();
                    steps++;
                }

                if (s.empty()) return steps + 1;
                else s.back() = '1';
            }
            
            else s.pop_back();
            steps++;
        }

        return steps;
    }
};