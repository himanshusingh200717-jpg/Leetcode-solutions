class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ans;
        int n=groupSizes.size();
        vector<vector<int>>mp(n+1);
        for(int i=0;i<n;i++){
            int j=groupSizes[i];
            mp[j].push_back(i);
            if(mp[j].size()==j){
                ans.push_back(mp[j]);
                mp[j]={};
            }
        }
        return ans;
        
    }
};