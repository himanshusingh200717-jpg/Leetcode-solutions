class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        int count=0;
        for(int x:nums){
            if(x!=mx&&x!=mn)
            return x;

        }
        return -1;
        
    }
};