class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<int>result;
        for(auto q:queries){
            int len=upper_bound(prefix.begin(),prefix.end(),q)-prefix.begin();
            result.push_back(len);
        }
        return result;
        
    }
};