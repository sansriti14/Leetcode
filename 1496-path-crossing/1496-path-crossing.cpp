class Solution {
public:
    bool isPathCrossing(string path){
        pair<int, int> coordinates = {0, 0};
        set<pair<int, int>> s;
        s.insert(coordinates);
        
        for(int i = 0; i < path.length(); i++) {
            if(path[i] == 'N') coordinates.second += 1;
            else if(path[i] == 'E') coordinates.first += 1;
            else if(path[i] == 'W') coordinates.first -= 1;
            else if(path[i] == 'S') coordinates.second -= 1;
            
            if(s.find({coordinates.first, coordinates.second}) != s.end()) return true;
            else s.insert({coordinates.first, coordinates.second});
        }
        
        return false;
    }
};