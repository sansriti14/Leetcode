class Solution {
public:
    int largestInteger(int num) {
        string str = to_string(num);
        priority_queue<int> even_ele, odd_ele;
        
        for (auto &ch: str) {
            if ((ch - '0') % 2) odd_ele.push(ch);
            else even_ele.push(ch);
            
        }

        for (auto &ch: str) {
            if ((ch - '0') % 2) {
                ch = odd_ele.top();
                odd_ele.pop();
            }
            
            else {
                ch = even_ele.top();
                even_ele.pop();
            }
        }
        
        return stoi(str);
    }
};