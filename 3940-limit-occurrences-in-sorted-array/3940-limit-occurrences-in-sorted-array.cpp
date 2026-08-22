class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<int>ans;
        for(int x:nums){
            mp[x]++;
        }
        for(auto &it:mp){
            int count=min(it.second,k);
            while(count){
                ans.push_back(it.first);
                count--;
            }
        }
        return ans;
      
    }
};