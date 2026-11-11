class Solution {
public:
int solve(vector<int>& arr,int prev,int curr,unordered_map<int,int>&mp,vector<vector<int>>&dp){
    int target=arr[prev]+arr[curr];
    if(dp[prev][curr]!=-1)return dp[prev][curr];
    if(mp.find(target)==mp.end())return dp[prev][curr]=0;
    int next=mp[target];
    return dp[prev][curr]=1+solve(arr,curr,next,mp,dp);

}
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int>mp;
                int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int len=2+solve(arr,i,j,mp,dp);
                ans=max(ans,len);
            }
        }
        return ans>=3?ans:0;
    }
};