class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=0;
        for(int x:nums){
            if(st.count(x+diff)&&st.count(x+2*diff))
            ans++;
        }
        return ans;
        
    }
};