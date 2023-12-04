class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> temp = {"999","888","777","666","555","444","333","222","111","000"};
        for(auto it : temp) {
            if(num.find(it) != -1)
            return it;
        }
        
        return "";
    }
};