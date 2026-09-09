class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int x:nums){
            mp[x]++;
        }
        for(auto &it:mp){
            if(it.second==2)
            ans^=it.first;
        }
        return ans;
        
    }
};