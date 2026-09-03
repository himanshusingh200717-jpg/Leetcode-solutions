class Solution {
public:
int digitsum(int n){
    int sum=0;
    while(n>0){
        int x=n%10;
        sum+=x;
        n/=10;
    }
    return sum;
}

    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(digitsum(nums[i])==i){
                return i;
            }
        }
       return -1;
        
    }
};