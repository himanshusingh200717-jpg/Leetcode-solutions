class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int>mp;
                int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        vector<vector<int>>dp(n,vector<int>(n,2));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int need=arr[j]-arr[i];
                if(mp.find(need)!=mp.end()){
                    int k=mp[need];
                    if(k<i){
                        dp[i][j]=dp[k][i]+1;
                        ans=max(ans,dp[i][j]);
                    }
                }
   
            }
        }
        return ans>=3?ans:0;
    }
};