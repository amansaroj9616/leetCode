class Solution {
public:
    int numSquares(int n) {
        int maxSquare=sqrt(n);
        vector<vector<int>>dp(maxSquare+1,vector<int>(n+1,INT_MAX));
        for(int i=0;i<=maxSquare;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=maxSquare;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=dp[i-1][j];
            if(j>=i*i && dp[i][j-i*i]!=INT_MAX){
                dp[i][j]=min(dp[i][j] , dp[i][j-i*i]+1);
            }
            }
        }
        return dp[maxSquare][n];


        
    }
};