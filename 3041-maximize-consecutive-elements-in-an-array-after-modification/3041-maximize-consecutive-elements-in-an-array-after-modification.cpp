class Solution {
public:
int n;
vector<vector<int>>t;
int findmethod(int start,int target,vector<int>&nums){
    int j=lower_bound(nums.begin()+start,nums.end(),target)-nums.begin();
    if(j<n&&nums[j]==target){
        return j;
    }
    return -1;

}

    int maxSelectedElements(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        t.assign(n+1,vector<int>(2,0));
        int result=1;
        for(int i=n-1;i>=0;i--){
            for(int inc=0;inc<=1;inc++){
                int currval=nums[i]+inc;
                int len=1;
                int j=findmethod(i+1,currval+1,nums);
              if(j!=-1){
                  len=max(len,1+t[j][0]);
               }
               j=findmethod(i+1,currval,nums);
             if(j!=-1){
               len=max(len,1+t[j][1]);
               }
               t[i][inc]=len;
               result=max(result,len);

            }
        }
        
        return result;
    }
};