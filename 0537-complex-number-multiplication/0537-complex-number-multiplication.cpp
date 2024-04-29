class Solution {
private:
    int findRealCoefficient(string& num, int& i) {
        string temp = "";
        while (num[i] != '+') temp += num[i++];
        return stoi(temp);
    }
    
    int findImaginaryCoefficent(string& num, int i) {
        string temp = "";
        while (num[i] != 'i') temp += num[i++];
        return stoi(temp);
    }
    
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1, a2, b1, b2;
    
        int i = 0;
        a1 = findRealCoefficient(num1, i);
        i++;
        b1 = findImaginaryCoefficent(num1, i);
        
        i = 0;
        a2 = findRealCoefficient(num2, i);
        i++;
        b2 = findImaginaryCoefficent(num2, i);
        
        int x = (a1 * a2) - (b1 * b2);
        int y = (a1 * b2) + (b1 * a2);
        
        string ans = "";
        ans += (to_string(x) + '+' + to_string(y)) + 'i';
        
        return ans;
    }
};