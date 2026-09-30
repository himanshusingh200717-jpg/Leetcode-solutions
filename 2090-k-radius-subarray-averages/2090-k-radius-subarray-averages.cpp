class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n,-1);
        if(k==0)return nums;
        int windowsize=2*k+1;
        if(n<windowsize)return ans;
        long long sum=0;
        for(int i=0;i<windowsize;i++){
            sum+=nums[i];
        }
        int center=k;
        ans[center]=sum/windowsize;
        for(int i=windowsize;i<n;i++){
            sum-=nums[i-windowsize];
            sum+=nums[i];
            center=i-k;
            ans[center]=sum/windowsize;

        }
        return ans;

        
    }
};