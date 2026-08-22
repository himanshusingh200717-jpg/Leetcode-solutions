class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int x:bulbs){
            mp[x]++;
        }
        for(auto &it:mp){
            if(it.second%2!=0)
            ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};