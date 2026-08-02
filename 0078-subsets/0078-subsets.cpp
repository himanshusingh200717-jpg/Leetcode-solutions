class Solution {
public:
vector<int>subset;
vector<vector<int>>ans;
void solve(int index,vector<int>&nums){
    if(index==nums.size()){
        ans.push_back(subset);
        return;
    }
    solve(index+1,nums);
    subset.push_back(nums[index]);
    solve(index+1,nums);
    subset.pop_back();

}
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,nums);
        return ans;
        
        
    }
};