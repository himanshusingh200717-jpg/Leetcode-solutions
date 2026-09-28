class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int count;
        for(int x:nums){
            if(x==0)count++;
            else
            count=0;
            ans=ans+count;
        }
        return ans;
        
    }
};