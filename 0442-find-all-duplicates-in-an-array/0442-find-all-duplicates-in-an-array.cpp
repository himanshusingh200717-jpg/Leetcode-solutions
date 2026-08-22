class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        for(auto &it:mp){
            if(it.second==2){
                ans.push_back(it.first);
            }
        }
        return ans;
        
    }
};