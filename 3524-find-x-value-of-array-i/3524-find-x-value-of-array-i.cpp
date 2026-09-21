class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>prevcount(k,0);
        vector<long long>result(k,0);
        for(int i=0;i<n;i++){
            vector<long long>currcount(k,0);
            int currelerem=nums[i]%k;
            currcount[currelerem]++;
            for(int oldrem=0;oldrem<=k-1;oldrem++){
                int newrem=((long long)oldrem*nums[i]%k)%k;
                currcount[newrem]+=prevcount[oldrem];
            }
            prevcount=std::move(currcount);
            for(int x=0;x<=k-1;x++){
                result[x]+=prevcount[x];
            }
        }
        return result;
        
    }
};