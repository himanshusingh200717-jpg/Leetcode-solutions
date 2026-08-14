class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int sumleft=nums[0];
        int sumright=nums[n-1];
        vector<int>left(n,0);
        vector<int>right(n,0);
        vector<int>ans(n,0);
        for(int i=1;i<n;i++){
            left[i]=sumleft;
            sumleft+=nums[i];

        }
        for(int i= n-2;i>=0;i--){     
            right[i]=sumright;
            sumright+=nums[i];
        }
        for(int i=0;i<n;i++){
            ans[i]=abs(left[i]-right[i]);
            

        }
        return ans;
    }
};