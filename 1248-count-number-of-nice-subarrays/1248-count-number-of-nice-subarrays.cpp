class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;
        int oddcount=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1)
            oddcount++;
            if(mp.find(oddcount-k)!=mp.end()){
                ans+=mp[oddcount-k];
            }
            mp[oddcount]++;
        }
        return ans;
    }
};