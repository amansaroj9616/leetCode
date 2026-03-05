class Solution {
public:
    int minOperations(string s) {
        int st0=0;
        int st1=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(s[i]=='0'){
                    st1++;
                }
                else{
                    st0++;
                }
            }
            else {
                if(s[i]=='1'){
                    st1++;
                }
                else{
                    st0++;
                }
            }
        }
        return min(st0,st1);
    }
};