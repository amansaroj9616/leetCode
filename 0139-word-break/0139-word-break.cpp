class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // int n=s.size();
        // vector<bool>dp(n+1,0);
        // dp[0]=1;
        // for(int i=1;i<=n;i++){
        //     for(string &w : wordDict){
        //         int m=w.size();
        //         int start=i-m;
        //         if(start>=0 && dp[start] && s.substr(start,m)==w){
        //             dp[i]=1;
        //             break;
        //         }
        //     }
        // }
        // return dp[n];

        int n=s.size();
        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i;j++){
                if(dp[j] && find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};