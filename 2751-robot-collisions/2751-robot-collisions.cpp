class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<pair<int, int>> robotData;
        for (int i = 0; i < n; i++) {
            robotData.push_back({positions[i], i});
        }

        sort(begin(robotData), end(robotData));

        stack<int> indexStack;
        
        for (int i = 0; i < n; i++) {
            int index = robotData[i].second;
            char direction = directions[index];

            if (direction == 'L') {
                if (indexStack.empty()) {
                    indexStack.push(index);
                } 
                
                else {
                    if (directions[indexStack.top()] == 'R' && healths[indexStack.top()] == healths[index]) {
                        healths[indexStack.top()] = 0;
                        indexStack.pop();
                        healths[index] = 0;
                    } 
                    
                    else {
                        while (!indexStack.empty() && directions[indexStack.top()] == 'R' && healths[indexStack.top()] < healths[index]) {
                            healths[indexStack.top()] = 0;
                            indexStack.pop();
                            healths[index]--;
                        }

                        if (!indexStack.empty() && directions[indexStack.top()] == 'R' && healths[indexStack.top()] > healths[index]) {
                            healths[indexStack.top()]--;
                            healths[index] = 0;
                        } 
                        
                        else if (!indexStack.empty() && directions[indexStack.top()] == 'R' && healths[indexStack.top()] == healths[index]) {
                            healths[indexStack.top()] = 0;
                            healths[index] = 0;
                            indexStack.pop();
                        } 
                        
                        else {
                            indexStack.push(index);
                        }
                    }
                }
            } 
            
            else {
                indexStack.push(index);
            }
        }

        vector<int> ans;

        for (int health : healths) {
            if (health > 0) {
                ans.push_back(health);
            }
        }

        return ans;
    }
};
