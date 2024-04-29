class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1, a2, b1, b2;
    
        int i = 0;
        string temp = "";
        while (num1[i] != '+') temp += num1[i++];
        a1 = stoi(temp);
        
        i++;
        temp.clear();
        while (num1[i] != 'i') temp += num1[i++];
        b1 = stoi(temp);
        
        int j = 0;
        temp.clear();
        while (num2[j] != '+') temp += num2[j++];
        a2 = stoi(temp);
        
        j++;
        temp.clear();
        while (num2[j] != 'i') temp += num2[j++];
        b2 = stoi(temp);
        
        int x = (a1 * a2) - (b1 * b2);
        int y = (a1 * b2) + (b1 * a2);
        
        string ans = "";
        ans += (to_string(x) + '+' + to_string(y)) + 'i';
        
        return ans;
    }
};