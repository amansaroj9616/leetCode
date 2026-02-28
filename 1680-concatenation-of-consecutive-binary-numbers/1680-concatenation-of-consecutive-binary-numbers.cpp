class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod=1e9+7;
        long  result=0;
        for(int i=1;i<=n;i++){
            int width=bit_width((unsigned)i);
            result=((result<<width)|i)%mod;

        }

        return result;
        
    }
};