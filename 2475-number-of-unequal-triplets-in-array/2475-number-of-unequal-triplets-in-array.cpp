class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        int left=0;
        int right=nums.size();
        int ans=0;
        for(auto &[val,cnt]:mp){
            right-=cnt;
            ans+=left*cnt*right;
            left+=cnt;

        }
        return ans;

        
    }
};