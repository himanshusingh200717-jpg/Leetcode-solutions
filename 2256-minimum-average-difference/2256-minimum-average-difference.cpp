class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long total=0;
        int n=nums.size();
        long long prefix=0;
        int index=-1;
        int mn=INT_MAX;
        for(int x:nums){
            total+=x;
        }
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            int leftavg=prefix/(i+1);
            long long suffix=total-prefix;
            int rightavg;
            if(i==n-1){
                rightavg=0;
            }
            else
            rightavg=suffix/(n-i-1);
            int diff=abs(leftavg-rightavg);

            if(mn>diff){
                mn=diff;
                index=i;
            }
            

        }
        return index;
    }
};