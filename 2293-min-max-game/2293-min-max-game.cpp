class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while(nums.size()>1){
            int n=nums.size()/2;
            for(int i=0;i<n;i++){
                if(i%2==0){
                    nums[i]=min(nums[2*i],nums[2*i+1]);
                }else
                 nums[i]=max(nums[2*i],nums[2*i+1]);

            }
            nums.resize(n);
        }
        return nums[0];
    }
};