class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        vector<int>ans;
        int sumeven=0;
        for(int &x:nums){
            if(x%2==0)
            sumeven+=x;
        }
        for(int i=0;i<q;i++){
            int val=queries[i][0];
            int idx=queries[i][1];
            if(nums[idx]%2==0){
                sumeven-=nums[idx];
            }
            nums[idx]+=val;
            if(nums[idx]%2==0){
                sumeven+=nums[idx];


            }
            ans.push_back(sumeven);

        }
        return ans;
    }
};