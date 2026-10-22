class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int asc_count=0;
        int dsc_count=0;
        for(int i=1;i<n;i++){
            asc_count+=(nums[i]==(nums[i-1]+1)%n);
            dsc_count+=(nums[i-1]==(nums[i]+1)%n);
        }
        if(asc_count==n-1&&nums[0]==0)return 0;
        if(asc_count==n-1){
            int leftrot=n-nums[0];
            int rightrot=1+(1+nums.back())+1;
            return min(leftrot,rightrot);
        }
        if(dsc_count==n-1){
            int leftrot=n-nums.back()+1;
            int rightrot=(nums[0]+1)%n+1;
            return min(leftrot,rightrot);
        }
        return -1;
    }
};