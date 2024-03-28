class Solution {   
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendCodes (begin(deadends), end(deadends));
        
        if(target == "0000") return 0;
        if(deadendCodes.find("0000") != deadendCodes.end()) return -1;
        
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        
        unordered_map<string, bool> visited;
        visited["0000"] = true;
        
        while (!q.empty()) {
            auto [currCode, currTurns] = q.front();
            q.pop();
            
            if (currCode == target) return currTurns;
            
            for (int i = 0; i < 4; i++) {
                char originalDigit = currCode[i];
                
                for(int j = -1; j <= 1; j += 2) {
                    char modifiedDigit = (originalDigit - '0' + j + 10) % 10 + '0'; 
                    currCode[i] = modifiedDigit;
                    
                    if (visited.find(currCode) == visited.end() && deadendCodes.find(currCode) == deadendCodes.end()) {
                        visited[currCode] = true;
                        q.push({currCode, currTurns + 1});
                    }
                }
                
                currCode[i] = originalDigit;
            }
        }
        
        return -1;
    }
};