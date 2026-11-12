class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int icount=0;
        int dcount=0;
        int maxicount=0;
        int maxdcount=0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i]){
                icount++;
                maxicount=max(maxicount,icount);
            }
            else
            icount=0;
            if(nums[i+1]<nums[i]){
                dcount++;
               maxdcount=max(maxdcount,dcount);
            }
            else
            dcount=0;
            
        }
        return 1+max(maxicount,maxdcount);
        
    }
};