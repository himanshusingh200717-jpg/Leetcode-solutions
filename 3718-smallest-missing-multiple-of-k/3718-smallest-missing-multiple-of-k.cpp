class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st(nums.begin(),nums.end());
        int count=1;
        while(st.count(k*count)){
            count++;
        }
        return count*k;
        
    }
};