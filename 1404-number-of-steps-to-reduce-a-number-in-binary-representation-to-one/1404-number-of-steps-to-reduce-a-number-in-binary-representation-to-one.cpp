class Solution {
public:
    int numSteps(string s) {
        int step=0;
        int carry=0;
        int n=s.size();
        for(int i=n-1;i>0;i--){
            int bits=s[i]-'0';
            if(bits+carry==1){
                step+=2;
                carry=1;
            }else{
                step+=1;
            }
        }
        if(carry){
            step+=1;
        }
        return step;

        
    }
};