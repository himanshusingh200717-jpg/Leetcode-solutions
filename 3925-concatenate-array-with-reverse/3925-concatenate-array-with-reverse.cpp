class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int>ans;
        for(int x:nums){
            ans.push_back(x);

        }
        reverse(nums.begin(),nums.end());
        for(int x:nums){
            ans.push_back(x);
        }
        return ans;
    }
};