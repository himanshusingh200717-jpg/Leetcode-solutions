class Solution {
public:
 int digitsum(int n){
            int sum=0;
            while(n>0){
                int rem=n%10;
                sum+=rem;
                n/=10;

            }
            return sum;
        }
    int differenceOfSum(vector<int>& nums) {
       
        int sum1=0;
        int sum2=0;
        for(int x:nums){
            sum1+=x;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]/10==0)
            sum2+=nums[i];
            else
            sum2+=digitsum(nums[i]);
            
        }
        return abs(sum1-sum2);

        
    }
};