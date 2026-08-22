class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=1;
        while(j<n){
            reverse(nums.begin()+i,nums.begin()+j+1);
            i+=2;
            j+=2;

        }
        return nums;
        
        
    }
};