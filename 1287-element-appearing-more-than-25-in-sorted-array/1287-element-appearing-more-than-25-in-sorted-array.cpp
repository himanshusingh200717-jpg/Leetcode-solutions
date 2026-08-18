class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int x:arr){
            mp[x]++;
        }
        for(auto &it:mp){
            if(it.second>n/4){
                return it.first;
            }
        }
        return -1;
        
    }
};