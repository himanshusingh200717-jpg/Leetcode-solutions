class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int ans=INT_MIN;
        mp[0]=-1;
        int currsum=0;
        for(int i=0;i<n;i++){
            currsum+=(nums[i]==1)?1:-1;
            if(mp.find(currsum)!=mp.end()){
                ans=max(ans,i-mp[currsum]);
            }else
            mp[currsum]=i;
        }
        return ans==INT_MIN?0:ans;
    }
};