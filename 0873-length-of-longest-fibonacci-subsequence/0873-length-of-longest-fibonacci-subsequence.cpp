class Solution {
public:
int solve(vector<int>& arr,int prev,int curr,unordered_map<int,int>&mp){
    int target=arr[prev]+arr[curr];
    if(mp.find(target)==mp.end())return 0;
    int next=mp[target];
    return 1+solve(arr,curr,next,mp);

}
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int>mp;
                int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int len=2+solve(arr,i,j,mp);
                ans=max(ans,len);
            }
        }
        return ans>=3?ans:0;
    }
};