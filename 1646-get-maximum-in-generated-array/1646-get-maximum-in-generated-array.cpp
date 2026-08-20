class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int>nums(n+1);
        if(n==0)return 0;
        nums[0]=0;
        nums[1]=1;
        int maxel=INT_MIN;
        for(int i=0;i<=n;i++){
            if(2*i>=2&&2*i<=n)
            nums[2*i]=nums[i];
            if(2*i+1>=2&&2*i+1<=n)
            nums[2*i+1]=nums[i]+nums[i+1];
           
            
        }
        for(int i=0;i<=n;i++){
             maxel=max(maxel,nums[i]);

        }
        return maxel;

        
    }
};