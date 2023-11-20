class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        for(int i = 1; i < travel.size(); i++){
            travel[i] += travel[i - 1];
        }
        
        int p = 0, g = 0, m = 0;
        int p_count = 0, g_count = 0, m_count = 0;
        for(int i = 0; i < garbage.size(); i++) {
            for(int j = 0; j < garbage[i].size(); j++) {
                if(garbage[i][j] == 'G'){
                    g_count++;
                    if(i > 0) g = travel[i - 1];
                }
                
                else if(garbage[i][j] == 'M') {
                    m_count++;
                    if(i > 0) m = travel[i - 1];
                    
                }
                
                else if(garbage[i][j] == 'P') {
                    p_count++;
                    if(i > 0) p = travel[i - 1];
                }
            }
        }
        
        return (p + g + m + p_count + g_count + m_count);
    }
};