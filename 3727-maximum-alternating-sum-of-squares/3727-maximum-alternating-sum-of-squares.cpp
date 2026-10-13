class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        vector<int>as(nums);
        reverse(nums.begin(),nums.end());
        vector<int>ds(nums);
        vector<int>ans;
        int a=0;
        int b=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                ans.push_back(ds[a]);
                a++;
            }else{
            ans.push_back(as[b]);
            b++;
            }
        }
        long long sum=0;
        for(int i=0;i<ans.size();i++){
            if(i%2==0)sum+=(ans[i]*ans[i]);
            else
            sum-=(ans[i]*ans[i]);
        }
        return sum;
    }
};