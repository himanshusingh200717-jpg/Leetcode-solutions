class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
       for(int x:nums){
        sum+=x;
       }
       int prefix=0;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=(nums[i]*i-(prefix)+(sum-prefix-nums[i])-nums[i]*(n-i-1));
            prefix+=nums[i];
        }
        return ans;
        
    }
};