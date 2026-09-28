class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result=0;
        long long len=0;
        for(int x:nums){
            if(x==0){
                len++;
            }
            else{
                result+=len*(len+1)/2;
                len=0;

            }
            
        }
        result+=len*(len+1)/2;
        return result;
        
    }
};