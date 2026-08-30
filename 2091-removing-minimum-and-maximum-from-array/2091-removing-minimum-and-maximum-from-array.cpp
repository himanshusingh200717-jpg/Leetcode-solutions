class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }
        int mn=INT_MAX;
        int mx=INT_MIN;
        int index1=-1;
        int index2=-1;
        int i=0;
        int j=0;
        while(i<n){
            if(nums[i]<mn){
                mn=nums[i];
                index1=i;
            }
            i++;
           
        }
        while(j<n){
            if(nums[j]>mx){
                mx=nums[j];
                index2=j;
            }
            j++;
        }
        int left=max(index1,index2)+1;
        int right=max(n-index1,n-index2);
        int oneleftoneright1=index1+1+(n-index2);
        int oneleftoneright2=index2+1+(n-index1);
        return min({left,right,oneleftoneright1,oneleftoneright2});
     
    }
};