class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        if(i == n) return 0;
        
        int sign = 1;
        if(s[i] == '-') sign = -1;
        
        long long num = 0;
        if(s[i] == '-' || s[i] == '+') ++i;
        while(i < n && s[i] == '0') i++;
        
        int j = i;
        while(j < n && isdigit(s[j])) j++;
        
        if(j - i > 10) return (sign == 1) ? INT_MAX : INT_MIN;
        
        long long place = pow(10, j - i - 1);
        
        while(i < j) {
            num += ((s[i] - '0') * place);
            place /= 10;
            i++;
        }
        
        num = num * sign;
        if(num < INT_MIN) return INT_MIN;
        if(num > INT_MAX) return INT_MAX;
        return num;
    }
};