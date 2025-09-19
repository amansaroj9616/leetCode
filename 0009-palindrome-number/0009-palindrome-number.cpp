class Solution {
public:
    bool isPalindrome(int x) {
        long long revNumber=0;
        if(x<0){
            return false;
        }
        int y=x;
        while(y>0){
            int lastDigit=y%10;
           revNumber=(revNumber*10)+lastDigit;
            y=y/10;
            
        }
        return revNumber==x;
        
        
    }
};