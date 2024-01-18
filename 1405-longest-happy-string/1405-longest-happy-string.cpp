class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});
        
        string str = "";
        while(!pq.empty()) {
            auto [curr_freq, curr_char] = pq.top();
            pq.pop();
            
            int n = str.length();
            if(n >= 2 && (str[n - 1] == curr_char) && (str[n - 2] == curr_char)) {
                if(pq.empty()) break;
                
                auto [next_freq, next_char] = pq.top();
                pq.pop();
                
                str += next_char;
                if(--next_freq > 0) {
                    pq.push({next_freq, next_char});
                }
                
                pq.push({curr_freq, curr_char});
            }
            
            else {
                str += curr_char;
                if(--curr_freq > 0) {
                    pq.push({curr_freq, curr_char});
                }
            }
        }
        
        return str;
    }
};