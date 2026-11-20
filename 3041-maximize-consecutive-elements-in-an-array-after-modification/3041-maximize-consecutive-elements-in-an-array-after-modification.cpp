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
int solve(int i,int inc,vector<int>&nums){
     if (i >= n) return 0;
    if(t[i][inc]!=-1)return t[i][inc];
    int len=1;
    int currval=nums[i]+inc;
    int j=findmethod(i+1,currval+1,nums);
    if(j!=-1){
        len=max(len,1+solve(j,0,nums));
    }
    j=findmethod(i+1,currval,nums);
    if(j!=-1){
        len=max(len,1+solve(j,1,nums));
    }
    return t[i][inc]=len;


}
    int maxSelectedElements(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        t.assign(n+1,vector<int>(2,-1));
        int result=1;
        for(int i=0;i<n;i++){
            result=max({result,solve(i,0,nums),solve(i,1,nums)});
        }
        return result;
    }
};