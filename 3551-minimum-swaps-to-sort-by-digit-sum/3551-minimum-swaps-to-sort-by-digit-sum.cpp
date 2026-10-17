class Solution {
public:
int digitsum(int n){
    int sum=0;
    while(n>0){
        int rem=n%10;
        sum+=rem;
        n/=10;
    }
    return sum;
}

    int minSwaps(vector<int>& nums) {
        vector<int>sorted(nums);
        int n=nums.size();
        auto lambda =[&](int num1,int num2){
            int d1=digitsum(num1);
            int d2=digitsum(num2);
            if(d1!=d2)return d1<d2;
            else
            return num1<num2;
        };
        sort(sorted.begin(),sorted.end(),lambda);
        unordered_map<int,int>valtoidx;
        for(int i=0;i<n;i++){
            valtoidx[nums[i]]=i;
        }
        int count=0;
        for(int i=0;i<n;i++){
            int curr=nums[i];
            int expected=sorted[i];
            if(expected==curr)continue;
            int idx=valtoidx[expected];
            nums[i]=expected;
            nums[idx]=curr;
            valtoidx[expected]=i;
            valtoidx[curr]=idx;
            count++;
        }
        return count;
    }
};