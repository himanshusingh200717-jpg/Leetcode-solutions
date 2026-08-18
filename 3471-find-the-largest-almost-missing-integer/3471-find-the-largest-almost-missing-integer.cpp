class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int i=0;
        int n=nums.size();
        int ans=-1;
        unordered_map<int,int>mp;
        while(k<=n){
            unordered_set<int>st;
            for(int a=i;a<k;a++){
                st.insert(nums[a]);
            }
            for(auto &x:st){
                mp[x]++;
            }
            i++;
            k++;

        }
        for(auto &it:mp){
            if(it.second==1){
                ans=max(ans,it.first);
            }
        }
        return ans;
    }
};