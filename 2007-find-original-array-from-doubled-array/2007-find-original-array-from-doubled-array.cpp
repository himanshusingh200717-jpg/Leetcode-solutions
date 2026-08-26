class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        sort(changed.begin(),changed.end());
        vector<int>ans;
        if(n%2!=0)return {};
        map<int,int>mp;
        for(int &x:changed){
            mp[x]++;
        }
        for(int &x:changed){
            int twice=2*x;
            if(mp[x]==0)continue;
            if(mp.find(twice)==mp.end()||mp[twice]==0)return {};
            ans.push_back(x);
            mp[x]--;
            mp[twice]--;

        }
        return ans;
        
    }
};