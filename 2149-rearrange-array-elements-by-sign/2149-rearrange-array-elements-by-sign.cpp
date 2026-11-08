class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int p=0;
        int n=1;
        vector<int>result(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                result[p]=nums[i];
                p+=2;
            }else
            {
                result[n]=nums[i];
                n+=2;
            }
        }
        return result;
    }
};