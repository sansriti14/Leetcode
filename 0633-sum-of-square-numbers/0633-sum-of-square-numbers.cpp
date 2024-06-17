class Solution {
public:
    bool judgeSquareSum(int c) {
        if((int)sqrt(c)*sqrt(c)==c)
            return true;
        
        long long l=1, r=(int)sqrt(c)*(int)sqrt(c), n=3;
        
        while(l<=r){
            if(l+r==c)
                return true;
            if(l+r<c){
                l=l+n;
                n=n+2;
            }
            else
                r=pow(((int)sqrt(r)-1),2);
        }
        
        return l+r==c;
    }
};