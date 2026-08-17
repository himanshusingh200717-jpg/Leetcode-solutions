class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>prefixsum(n+1,0);
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            prefixsum[i+1]=prefixsum[i]+stoneValue[i];
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                for(int k=i;k<j;k++){
                    int leftsum=prefixsum[k+1]-prefixsum[i];
                    int rightsum=prefixsum[j+1]-prefixsum[k+1];
                    if(leftsum<rightsum){
                        dp[i][j]=max(dp[i][j],leftsum+dp[i][k]);
                    }
                    else if(leftsum>rightsum){
                         dp[i][j]=max(dp[i][j],rightsum+dp[k+1][j]);
                        
                    }else
                    dp[i][j]=max(dp[i][j],leftsum+max(dp[i][k],dp[k+1][j]));

                    
                }
            }
        }
        return dp[0][n-1];
        

        
    }
};