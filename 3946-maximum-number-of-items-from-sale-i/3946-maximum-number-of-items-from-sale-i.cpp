class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
         int minprice=INT_MAX;
        vector<int>copies(n,0);
        for(int i=0;i<n;i++){
            minprice=min(minprice,items[i][1]);
            int copy=0;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(items[j][0]%items[i][0]==0)
                copy++;
            }
            copies[i]=copy;
        }
        vector<vector<int>>dp(n+1,vector<int>(budget+1,0));
        for(int b=0;b<=budget;b++){
            dp[0][b]=b/minprice;
        }
        for(int i=1;i<=n;i++){
            for(int b=0;b<=budget;b++){
                int price=items[i-1][1];
                int take=0;
                int skip=0;
                if(price<=b){
                    take=1+copies[i-1]+dp[i-1][b-price];
                }
                skip=dp[i-1][b];
                dp[i][b]=max(take,skip);
                

            }
        }
        return dp[n][budget];
    }
};